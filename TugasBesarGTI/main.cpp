#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "imageloader.h"

int winW = 900, winH = 600;

enum GameState { ENGINE_START, PLAYING, GAME_OVER, GAME_FINISHED };
GameState currentState = PLAYING;

float camOffsetY  =  1.8f;       
float camAngleX   =  12.0f;      
float camDistance =  6.5f;       

float carPosX      = 0.0f;       
float carPosZ      = 0.0f;       
bool keys[256];                  

float carSpeed     = 0.0f;       
const float MAX_SPEED = 0.35f;  
const float ACCEL = 0.004f; 
const float FRICTION = 0.002f; 
const float BRAKE_DECEL = 0.008f; 
const float STEER_SPEED = 0.12f;  

float gas = 100.0f;
const float GAS_BURN = 0.071f;  
const float GAS_IDLE = 0.004f;
const float FINISH_Z = 1000.0f;

struct Jerrycan {
    float x, z;
    bool  collected;
};
std::vector<Jerrycan> jerrycans;
const int   MAX_JERRYCANS = 3;
const float JERRY_PICKUP_R = 1.8f;   
float        jerryBobTime = 0.0f;   

// --- Rock obstacle ---
struct Rock {
    float x, z;
    bool  hit;
};
std::vector<Rock> rocks;
const float ROCK_HIT_R = 1.8f;

struct WorldObject {
    int   type; 
    float x, z;
    float param1, param2, param3;
    float scale; 
};

std::vector<WorldObject> worldObjects;
float lastGeneratedZ = 60.0f;
const float CHUNK_SIZE = 45.0f; 
const float RENDER_AHEAD = 200.0f;
const float CULL_BEHIND = 80.0f;

const float TREE_SCALE_MIN = 1.5f;
const float TREE_SCALE_MAX = 2.5f;

bool spawnLightThisChunk = true;

GLuint skyTexID = 0;       
GLuint grassTexID = 0;     
GLuint asphaltTexID = 0;   
GLuint bgTreeTexID = 0;     
GLuint glassTexID = 0;      
GLuint warehouseTexID = 0;  
GLuint boxTexID = 0;

bool loadTextureFromImage(const char* filename, GLuint& texID) {
    Image img;
    if (!img.loadBMP(filename)) return false;
    
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.getWidth(), img.getHeight(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, img.getPixels());
    return true;
}

bool loadTextureWithBlackAsAlpha(const char* filename, GLuint& texID) {
    Image img;
    if (!img.loadBMP(filename)) return false;
    
    int width = img.getWidth();
    int height = img.getHeight();
    
    std::vector<unsigned char> rgbaData(width * height * 4);
    unsigned char* rgbPixels = (unsigned char*)img.getPixels();
    
    for (int i = 0; i < width * height; i++) {
        unsigned char r = rgbPixels[i * 3 + 0];
        unsigned char g = rgbPixels[i * 3 + 1];
        unsigned char b = rgbPixels[i * 3 + 2];
        
        rgbaData[i * 4 + 0] = r;
        rgbaData[i * 4 + 1] = g;
        rgbaData[i * 4 + 2] = b;
        
        if (r == 0 && g == 0 && b == 0) {
            rgbaData[i * 4 + 3] = 0;   
        } else {
            rgbaData[i * 4 + 3] = 255; 
        }
    }
    
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, &rgbaData[0]);
    return true;
}

int getTextWidth(const char* str, void* font) {
    int width = 0;
    while (*str) {
        width += glutBitmapWidth(font, *str++);
    }
    return width;
}

void drawString2D(float x, float y, const char* str, void* font = GLUT_BITMAP_HELVETICA_18) {
    glRasterPos2f(x, y);
    while (*str) glutBitmapCharacter(font, *str++);
}

void drawCylinder(float radius, float height, int sl, int st) {
    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, radius, radius, height, sl, st);
    gluDeleteQuadric(q);
}

float seededRand(int seed) {
    unsigned int s = (unsigned int)(seed * 1664525u + 1013904223u);
    s ^= s >> 16;
    return (float)(s & 0xFFFF) / 65535.0f;
}

void drawStreetLight(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.35f, z); 
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(0, 3.0f, 0);
    glScalef(0.2f, 6.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
    float sideOffset = (x < 0) ? 0.5f : -0.5f;
    glPushMatrix();
    glTranslatef(sideOffset, 6.0f, 0);
    glScalef(1.2f, 0.3f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();
    float glowOffset = (x < 0) ? 0.8f : -0.8f;
    glPushMatrix();
    glTranslatef(glowOffset, 5.8f, 0);
    glColor3f(1.0f, 0.9f, 0.5f);
    glutSolidSphere(0.3f, 8, 8);
    glPopMatrix();
    glPopMatrix();
}

void drawTreePine(float x, float z, float sc) {
    glPushMatrix(); glTranslatef(x, 0.0f, z); glScalef(sc, sc, sc);
    glColor3f(0.35f, 0.2f, 0.05f); glPushMatrix(); glTranslatef(0, 0.6f, 0); glScalef(0.3f, 1.5f, 0.3f); glutSolidCube(1); glPopMatrix();
    glColor3f(0.05f, 0.45f, 0.05f);
    for (int i = 0; i < 3; i++) {
        glPushMatrix(); glTranslatef(0, 1.0f + i * 0.55f, 0); glRotatef(-90, 1, 0, 0); glutSolidCone(1.0f - i * 0.25f, 0.85f, 10, 10); glPopMatrix();
    }
    glPopMatrix();
}

void drawTreePalm(float x, float z, float sc) {
    glPushMatrix(); glTranslatef(x, 0.0f, z); glScalef(sc, sc, sc);
    glColor3f(0.15f, 0.12f, 0.10f); glPushMatrix(); glTranslatef(0, 0.18f, 0); glScalef(0.55f, 0.36f, 0.55f); glutSolidCube(1); glPopMatrix();
    glColor3f(0.50f, 0.30f, 0.10f); glPushMatrix(); glTranslatef(0, 0.36f, 0); glRotatef(-90, 1, 0, 0); drawCylinder(0.07f, 0.45f, 8, 4); glPopMatrix();
    glColor3f(0.14f, 0.58f, 0.14f);
    for (int i = 0; i < 7; i++) {
        float t = (float)i / 6.0f; float r = 0.52f * (1.0f - t * 0.72f); float yOff = 0.80f + t * 2.05f;
        glPushMatrix(); glTranslatef(0, yOff, 0); glutSolidSphere(r, 10, 8); glPopMatrix();
    }
    glPopMatrix();
}

void drawTreeBranchy(float x, float z, float sc) {
    glPushMatrix(); glTranslatef(x, 0.0f, z); glScalef(sc, sc, sc);
    glColor3f(0.45f, 0.28f, 0.08f); glPushMatrix(); glTranslatef(0, 1.0f, 0); glScalef(0.35f, 2.5f, 0.35f); glutSolidCube(1); glPopMatrix();
    glColor3f(0.15f, 0.55f, 0.15f);
    float off[4][2] = { {0.6f, 0}, {-0.6f, 0}, {0, 0.6f}, {0, -0.6f} };
    for (int i = 0; i < 4; i++) {
        glPushMatrix(); glTranslatef(off[i][0] * 0.6f, 2.3f, off[i][1] * 0.6f); glutSolidSphere(0.65f, 8, 8); glPopMatrix();
    }
    glPushMatrix(); glTranslatef(0, 2.9f, 0); glutSolidSphere(0.7f, 8, 8); glPopMatrix();
    glPopMatrix();
}

void drawTree(const WorldObject& o) {
    float sc = o.scale;
    switch (o.type % 2) {
        case 0: drawTreePine(o.x, o.z, sc);    break;
        case 1: drawTreeBranchy(o.x, o.z, sc); break;
    }
}

void drawBuildingBox(float x, float z, float w, float h, float d, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    
    if (boxTexID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, boxTexID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1.0f, 1.0f, 1.0f);
        
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 2.5f); glVertex3f( w/2, h,   d/2); 
        glTexCoord2f(0.0f, 2.5f); glVertex3f(-w/2, h,   d/2);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 2.5f); glVertex3f(-w/2, h,   -d/2);
        glTexCoord2f(0.0f, 2.5f); glVertex3f( w/2, h,   -d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( w/2, 0.0f, -d/2);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f,  d/2);
        glTexCoord2f(1.0f, 2.5f); glVertex3f(-w/2, h,    d/2);
        glTexCoord2f(0.0f, 2.5f); glVertex3f(-w/2, h,   -d/2);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 2.5f); glVertex3f(w/2, h,   -d/2);
        glTexCoord2f(0.0f, 2.5f); glVertex3f(w/2, h,    d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(w/2, 0.0f,  d/2);
        
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-w/2, h, -d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, h,  d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( w/2, h,  d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( w/2, h, -d/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        glColor3f(0.7f, 0.35f, 0.3f);
        glPushMatrix(); glTranslatef(0.0f, h/2, 0.0f); glScalef(w, h, d); glutSolidCube(1.0f); glPopMatrix();
    }
    
    glPopMatrix();
}

void drawBuildingSetback(float x, float z) {
    glPushMatrix(); 
    glTranslatef(x, 0.0f, z);
    glColor3f(0.75f, 0.7f, 0.65f);
    glPushMatrix(); glTranslatef(0.0f, 2.625f, 0.0f); glScalef(9.0f, 6.0f, 7.0f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 7.625f, 0.0f); glScalef(7.0f, 5.0f, 5.5f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 11.625f, 0.0f); glScalef(4.5f, 4.0f, 4.0f); glutSolidCube(1.0f); glPopMatrix();
    glPopMatrix();
}

void drawBuildingGlass(float x, float z) {
    float w = 7.0f, h = 16.0f, d = 5.0f;
    glPushMatrix(); 
    glTranslatef(x, 0.0f, z);

    if (glassTexID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, glassTexID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1.0f, 1.0f, 1.0f); 
        
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 3.0f); glVertex3f( w/2, h,   d/2);
        glTexCoord2f(0.0f, 3.0f); glVertex3f(-w/2, h,   d/2);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 3.0f); glVertex3f(-w/2, h,   -d/2);
        glTexCoord2f(0.0f, 3.0f); glVertex3f( w/2, h,   -d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( w/2, 0.0f, -d/2);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f,  d/2);
        glTexCoord2f(1.0f, 3.0f); glVertex3f(-w/2, h,    d/2);
        glTexCoord2f(0.0f, 3.0f); glVertex3f(-w/2, h,   -d/2);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 3.0f); glVertex3f(w/2, h,   -d/2);
        glTexCoord2f(0.0f, 3.0f); glVertex3f(w/2, h,    d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(w/2, 0.0f,  d/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        glColor3f(0.2f, 0.35f, 0.55f);
        glPushMatrix(); glTranslatef(0.0f, h/2, 0.0f); glScalef(w, h, d); glutSolidCube(1.0f); glPopMatrix();
    }
    glColor3f(0.15f, 0.15f, 0.15f);
    glPushMatrix(); glTranslatef(0.0f, h + 0.2f, 0.0f); glScalef(w + 0.6f, 0.4f, d + 0.6f); glutSolidCube(1.0f); glPopMatrix();
    glPopMatrix();
}

void drawBuildingWarehouse(float x, float z) {
    float w = 8.0f, h = 6.5f, d = 7.5f;
    glPushMatrix(); 
    glTranslatef(x, 0.0f, z);
    
    if (warehouseTexID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, warehouseTexID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1.0f, 1.0f, 1.0f); 
        
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( w/2, 0.0f, d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( w/2, h,   d/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-w/2, h,   d/2);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-w/2, h,   -d/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( w/2, h,   -d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( w/2, 0.0f, -d/2);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-w/2, 0.0f,  d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-w/2, h,    d/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-w/2, h,   -d/2);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(w/2, 0.0f, -d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(w/2, h,   -d/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(w/2, h,    d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(w/2, 0.0f,  d/2);
        
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-w/2, h, -d/2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-w/2, h,  d/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( w/2, h,  d/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( w/2, h, -d/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        glColor3f(0.95f, 0.92f, 0.85f);
        glPushMatrix(); glTranslatef(0.0f, h/2, 0.0f); glScalef(w, h, d); glutSolidCube(1.0f); glPopMatrix();
    }
    
    glColor3f(0.35f, 0.65f, 0.85f);
    glPushMatrix(); glTranslatef(0.0f, 6.425f, 0.0f); glScalef(9.0f, 0.6f, 8.3f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.95f, 0.65f, 0.25f);
    glPushMatrix(); glTranslatef(0.0f, 1.225f, 3.77f); glScalef(2.2f, 3.2f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.55f, 0.35f, 0.25f);
    glPushMatrix(); glTranslatef(2.5f, 7.875f, -2.0f); glScalef(1.2f, 3.5f, 1.2f); glutSolidCube(1.0f); glPopMatrix();
    
    glPopMatrix();
}

void drawBuildingTower(float x, float z) {
    glPushMatrix(); glTranslatef(x, 0.0f, z);
    glColor3f(0.5f, 0.45f, 0.4f);
    glPushMatrix(); glTranslatef(0.0f, 7.625f, 0.0f); glScalef(4.5f, 16.0f, 4.5f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.55f, 0.5f, 0.45f);
    glPushMatrix(); glTranslatef(0.0f, 4.125f, 0.0f); glScalef(5.2f, 0.4f, 5.2f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 9.125f, 0.0f); glScalef(5.2f, 0.4f, 5.2f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 14.125f, 0.0f); glScalef(5.2f, 0.4f, 5.2f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.55f, 0.1f, 0.1f);
    glPushMatrix(); glTranslatef(0.0f, 16.025f, 0.0f); glScalef(4.0f, 0.6f, 4.0f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 16.625f, 0.0f); glScalef(3.0f, 0.6f, 3.0f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 17.225f, 0.0f); glScalef(2.0f, 0.6f, 2.0f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 18.225f, 0.0f); glScalef(0.6f, 1.4f, 0.6f); glutSolidCube(1.0f); glPopMatrix();
    glPopMatrix();
}

void drawBuilding(const WorldObject& o) {
    int variant = o.type % 5;
    switch (variant) {
        case 0: drawBuildingBox(o.x, o.z, 8.0f, o.param2, 6.0f, 0.68f, 0.63f, 0.58f); break;
        case 1: drawBuildingSetback(o.x, o.z); break;
        case 2: drawBuildingGlass(o.x, o.z);   break;
        case 3: drawBuildingWarehouse(o.x, o.z); break;
        case 4: drawBuildingTower(o.x, o.z);   break;
    }
}

// --- Draw jerrycan: lingkaran (ring) dipindah ke dasar lantai ---
void drawJerrycan(float x, float z, float bobY) {
    glPushMatrix(); 
    glTranslatef(x, 0.95f + bobY, z);

    static float angle = 0; 
    glRotatef(angle, 0, 1, 0); 
    angle += 0.8f; 
    if (angle > 360) angle -= 360;

    glScalef(1.6f, 1.6f, 1.6f);

    // Body merah
    glColor3f(0.85f, 0.12f, 0.08f); 
    glPushMatrix(); glScalef(0.30f, 0.42f, 0.20f); glutSolidCube(1.0f); glPopMatrix();

    // Tutup atas
    glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix(); glTranslatef(0, 0.23f, 0); glScalef(0.10f, 0.08f, 0.10f); glutSolidCube(1.0f); glPopMatrix();

    // Mulut/nozzle
    glColor3f(0.20f, 0.20f, 0.20f); 
    glPushMatrix(); glTranslatef(0, 0.25f, 0); glRotatef(90, 1, 0, 0); drawCylinder(0.025f, 0.14f, 6, 3); glPopMatrix();

    // Label kuning
    glColor3f(0.95f, 0.80f, 0.05f); 
    glPushMatrix(); glTranslatef(0, 0, 0.11f); glScalef(0.28f, 0.08f, 0.01f); glutSolidCube(1.0f); glPopMatrix();

    // Ring/lingkaran di dasar (y = -0.21f agar menempel lantai saat scale 1.6)
    glColor3f(1.0f, 0.6f, 0.0f); 
    glPushMatrix();
        glTranslatef(0, -0.21f, 0);
        glRotatef(-90, 1, 0, 0);   // hadap atas (XZ plane)
        GLUquadric* q = gluNewQuadric();
        gluDisk(q, 0.32f, 0.36f, 16, 1);
        gluDeleteQuadric(q);
    glPopMatrix();

    glPopMatrix();
}

// --- Draw rock --- (skala besar, setinggi ~mobil ~1.0 unit)
void drawRock(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    // Batu utama -- lebar & tinggi seperti badan mobil
    glColor3f(0.52f, 0.49f, 0.46f);
    glPushMatrix(); glTranslatef(0.0f, 0.85f, 0.0f); glScalef(1.6f, 1.1f, 1.3f); glutSolidSphere(0.9f, 12, 10); glPopMatrix();
    // Tonjolan atas kiri -- memberi kesan tidak rata
    glColor3f(0.44f, 0.41f, 0.38f);
    glPushMatrix(); glTranslatef(-0.55f, 1.4f, 0.2f); glScalef(1.0f, 0.75f, 0.85f); glutSolidSphere(0.6f, 10, 8); glPopMatrix();
    // Tonjolan kanan bawah
    glColor3f(0.48f, 0.45f, 0.42f);
    glPushMatrix(); glTranslatef(0.6f, 0.5f, -0.3f); glScalef(0.9f, 0.6f, 0.7f); glutSolidSphere(0.55f, 10, 8); glPopMatrix();
    // Bagian dasar/pondasi agar tidak melayang
    glColor3f(0.38f, 0.36f, 0.33f);
    glPushMatrix(); glTranslatef(0.0f, 0.18f, 0.0f); glScalef(1.8f, 0.35f, 1.5f); glutSolidSphere(0.7f, 10, 6); glPopMatrix();
    glPopMatrix();
}

void generateJerrycans() {
    jerrycans.clear();
    int seed = 42;
    for (int i = 0; i < MAX_JERRYCANS; i++) {
        Jerrycan jc;
        float seg = FINISH_Z / (MAX_JERRYCANS + 1);
        jc.z = seg * (i + 1) + (seededRand(seed + i * 15) * 40.0f - 20.0f);
        float lanes[] = { -4.0f, 0.0f, 4.0f }; 
        int laneIdx = (int)(seededRand(seed + i * 27) * 3);
        if (laneIdx > 2) laneIdx = 2;
        jc.x = lanes[laneIdx];
        jc.collected = false;
        jerrycans.push_back(jc);
    }
}

// Radius clearance per jenis objek (dipakai untuk cek tabrakan antar objek dunia)
static float objectRadius(const WorldObject& o) {
    if (o.type < 5)  return 3.5f;   // pohon
    if (o.type == 10) return 2.0f;  // lampu
    return 6.0f;                    // bangunan
}

// Kembalikan true bila posisi (x,z) cukup jauh dari semua objek yang sudah ada
static bool canPlace(float x, float z, float myRadius) {
    for (size_t i = 0; i < worldObjects.size(); i++) {
        float dx = worldObjects[i].x - x;
        float dz = worldObjects[i].z - z;
        float minDist = myRadius + objectRadius(worldObjects[i]);
        if (dx*dx + dz*dz < minDist*minDist) return false;
    }
    return true;
}

void generateChunk(float chunkStartZ) {
    int seed = (int)(chunkStartZ * 137);
    if (seed < 0) seed = -seed;

    // --- Pohon: 3 pohon per sisi, tersebar merata dalam chunk ---
    float treeSpacing = CHUNK_SIZE / 3.0f;
    for (int t = 0; t < 3; t++) {
        // Sisi kiri
        {
            float tz  = chunkStartZ + t * treeSpacing + seededRand(seed + t * 7 + 2) * treeSpacing * 0.7f;
            int   tt  = (int)(seededRand(seed + t * 13 + 3) * 4);
            float sc  = TREE_SCALE_MIN + seededRand(seed + t * 5 + 1) * (TREE_SCALE_MAX - TREE_SCALE_MIN);
            if (canPlace(-13.5f, tz, 3.5f)) {
                WorldObject ol; ol.type = tt; ol.x = -13.5f; ol.z = tz; ol.scale = sc;
                worldObjects.push_back(ol);
            }
        }
        // Sisi kanan
        {
            float tz2 = chunkStartZ + t * treeSpacing + seededRand(seed + t * 11 + 6) * treeSpacing * 0.7f;
            int   tt  = (int)(seededRand(seed + t * 17 + 9) * 4);
            float sc  = TREE_SCALE_MIN + seededRand(seed + t * 7 + 4) * (TREE_SCALE_MAX - TREE_SCALE_MIN);
            if (canPlace(13.5f, tz2, 3.5f)) {
                WorldObject or2; or2.type = tt; or2.x = 13.5f; or2.z = tz2; or2.scale = sc;
                worldObjects.push_back(or2);
            }
        }
    }

    // --- Lampu jalan setiap chunk ---
    if (spawnLightThisChunk) {
        float fixedZ = chunkStartZ + (CHUNK_SIZE / 2.0f);
        if (canPlace(-7.6f, fixedZ, 2.0f)) {
            WorldObject lightL; lightL.type = 10; lightL.x = -7.6f; lightL.z = fixedZ; lightL.scale = 1.0f;
            worldObjects.push_back(lightL);
        }
        if (canPlace(7.6f, fixedZ, 2.0f)) {
            WorldObject lightR; lightR.type = 10; lightR.x = 7.6f; lightR.z = fixedZ; lightR.scale = 1.0f;
            worldObjects.push_back(lightR);
        }
    }
    spawnLightThisChunk = !spawnLightThisChunk;

    // --- Bangunan: selalu spawn di kedua sisi ---
    {
        float bz = chunkStartZ + seededRand(seed + 11) * CHUNK_SIZE;
        int bt = (int)(seededRand(seed + 17) * 5);
        if (canPlace(-18.0f, bz, 6.0f)) {
            WorldObject b; b.type = bt + 5; b.x = -18.0f; b.z = bz;
            b.param1 = 3.5f + seededRand(seed + 29) * 2.0f;
            b.param2 = 11.0f + seededRand(seed + 31) * 4.0f;
            b.param3 = 2.5f + seededRand(seed + 37) * 1.5f;
            b.scale = 1.2f;
            worldObjects.push_back(b);
        }
    }
    {
        float bz = chunkStartZ + seededRand(seed + 41) * CHUNK_SIZE;
        int bt = (int)(seededRand(seed + 43) * 5);
        if (canPlace(18.0f, bz, 6.0f)) {
            WorldObject b; b.type = bt + 5; b.x = 18.0f; b.z = bz;
            b.param1 = 3.5f + seededRand(seed + 51) * 2.0f;
            b.param2 = 11.0f + seededRand(seed + 53) * 4.0f;
            b.param3 = 2.5f + seededRand(seed + 57) * 1.5f;
            b.scale = 1.2f;
            worldObjects.push_back(b);
        }
    }

    // Spawn satu batu di jalur dengan probabilitas 55%
    if (seededRand(seed + 77) > 0.45f) {
        float rz = chunkStartZ + seededRand(seed + 83) * CHUNK_SIZE;
        float lanes[] = { -4.5f, 0.0f, 4.5f };
        int laneIdx = (int)(seededRand(seed + 91) * 3);
        if (laneIdx > 2) laneIdx = 2;
        Rock rk;
        rk.x   = lanes[laneIdx];
        rk.z   = rz;
        rk.hit = false;
        rocks.push_back(rk);
    }
}

void updateWorld() {
    float targetZ = carPosZ + RENDER_AHEAD;
    while (lastGeneratedZ < targetZ) { generateChunk(lastGeneratedZ); lastGeneratedZ += CHUNK_SIZE; }

    float cullZ = carPosZ - CULL_BEHIND;

    std::vector<WorldObject> kept; kept.reserve(worldObjects.size());
    for (size_t i = 0; i < worldObjects.size(); i++) if (worldObjects[i].z > cullZ) kept.push_back(worldObjects[i]);
    worldObjects.swap(kept);

    // Cull batu yang sudah jauh di belakang atau sudah kena
    std::vector<Rock> keptR; keptR.reserve(rocks.size());
    for (size_t i = 0; i < rocks.size(); i++)
        if (!rocks[i].hit && rocks[i].z > cullZ) keptR.push_back(rocks[i]);
    rocks.swap(keptR);
}

void drawSkybox() {
    if (skyTexID == 0) return;
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, skyTexID);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glDepthMask(GL_FALSE);
    glPushMatrix();
    glTranslatef(carPosX, 0.0f, carPosZ);
    float size = 540.0f; 
    
    float y_low  = -150.0f; 
    float y_high = 380.0f; 
    float scrollSpeed = 0.0005f; 
    float texOffset = carPosZ * scrollSpeed;
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f + texOffset, 0.0f); glVertex3f(-size, y_low, -size);
    glTexCoord2f(1.0f + texOffset, 0.0f); glVertex3f( size, y_low, -size);
    glTexCoord2f(1.0f + texOffset, 1.0f); glVertex3f( size, y_high, -size);
    glTexCoord2f(0.0f + texOffset, 1.0f); glVertex3f(-size, y_high, -size);
    glTexCoord2f(0.0f - texOffset, 0.0f); glVertex3f( size, y_low,  size);
    glTexCoord2f(1.0f - texOffset, 0.0f); glVertex3f(-size, y_low,  size);
    glTexCoord2f(1.0f - texOffset, 1.0f); glVertex3f(-size, y_high,  size);
    glTexCoord2f(0.0f - texOffset, 1.0f); glVertex3f( size, y_high,  size);
    glTexCoord2f(0.0f + texOffset, 0.0f); glVertex3f(-size, y_low,  size);
    glTexCoord2f(1.0f + texOffset, 0.0f); glVertex3f(-size, y_low, -size);
    glTexCoord2f(1.0f + texOffset, 1.0f); glVertex3f(-size, y_high, -size);
    glTexCoord2f(0.0f + texOffset, 1.0f); glVertex3f(-size, y_high,  size);
    glTexCoord2f(0.0f - texOffset, 0.0f); glVertex3f( size, y_low, -size);
    glTexCoord2f(1.0f - texOffset, 0.0f); glVertex3f( size, y_low,  size);
    glTexCoord2f(1.0f - texOffset, 1.0f); glVertex3f( size, y_high,  size);
    glTexCoord2f(0.0f - texOffset, 1.0f); glVertex3f( size, y_high, -size);
    glTexCoord2f(0.0f, 0.0f + texOffset); glVertex3f(-size, y_high, -size);
    glTexCoord2f(1.0f, 0.0f + texOffset); glVertex3f( size, y_high, -size);
    glTexCoord2f(1.0f, 1.0f + texOffset); glVertex3f( size, y_high,  size);
    glTexCoord2f(0.0f, 1.0f + texOffset); glVertex3f(-size, y_high,  size);
    glEnd();
    glPopMatrix();
    glDepthMask(GL_TRUE);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}

void drawGround1() {
    float base = carPosZ - 50.0f; 
    float zStart = base; 
    float zEnd = base + 580.0f; 
    float roadW = 7.5f;
    
    if (asphaltTexID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, asphaltTexID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1.0f, 1.0f, 1.0f); 
    } else {
        glColor3f(0.18f, 0.18f, 0.18f); 
    }
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f); 
    if (asphaltTexID != 0) {
        float texZStart = zStart / 8.0f;
        float texZEnd   = zEnd / 8.0f;
        glTexCoord2f(0.0f, texZStart); glVertex3f(-roadW, 0.02f, zStart); 
        glTexCoord2f(1.0f, texZStart); glVertex3f( roadW, 0.02f, zStart);
        glTexCoord2f(1.0f, texZEnd);   glVertex3f( roadW, 0.02f, zEnd);   
        glTexCoord2f(0.0f, texZEnd);   glVertex3f(-roadW, 0.02f, zEnd);
    } else {
        glVertex3f(-roadW, 0.02f, zStart); 
        glVertex3f( roadW, 0.02f, zStart);
        glVertex3f( roadW, 0.02f, zEnd);   
        glVertex3f(-roadW, 0.02f, zEnd);
    }
    glEnd();
    
    if (asphaltTexID != 0) glDisable(GL_TEXTURE_2D);
    
    float sidewalkW = 3.5f, sidewalkH = 0.35f, blockLength = 3.0f;
    int startIdx = (int)(zStart / blockLength) - 1;
    int endIdx   = (int)(zEnd / blockLength) + 1;
    for (int i = startIdx; i <= endIdx; i++) {
        int val = i; if (val < 0) val = -val; 
        bool isLightGrey = (val % 2 == 0);
        if (isLightGrey) glColor3f(0.65f, 0.65f, 0.65f); 
        else glColor3f(0.40f, 0.40f, 0.40f);              
        float blockZ = i * blockLength + (blockLength / 2.0f);
        glPushMatrix(); 
        glTranslatef(-roadW - (sidewalkW / 2.0f), sidewalkH / 2.0f, blockZ); 
        glScalef(sidewalkW, sidewalkH, blockLength); 
        glutSolidCube(1); 
        glPopMatrix();
        glPushMatrix(); 
        glTranslatef(roadW + (sidewalkW / 2.0f), sidewalkH / 2.0f, blockZ); 
        glScalef(sidewalkW, sidewalkH, blockLength); 
        glutSolidCube(1); 
        glPopMatrix();
    }
    
    glColor3f(0.95f, 0.95f, 0.95f); 
    int startMark = (int)((carPosZ - 50) / 6.0f) - 1; 
    int endMark = (int)((carPosZ + RENDER_AHEAD) / 6.0f) + 1;
    for (int i = startMark; i <= endMark; i++) {
        glPushMatrix(); glTranslatef(-2.5f, 0.03f, i * 6.0f); glScalef(0.12f, 0.01f, 3.0f); glutSolidCube(1); glPopMatrix();
        glPushMatrix(); glTranslatef(2.5f, 0.03f, i * 6.0f);  glScalef(0.12f, 0.01f, 3.0f); glutSolidCube(1); glPopMatrix();
    }
}

void drawGround2() {
    float base = carPosZ - 50.0f; 
    float zStart = base; 
    float zEnd = base + 580.0f; 
    float outerEdge = 40.0f; 
    
    if (grassTexID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, grassTexID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1.0f, 1.0f, 1.0f);
    } else {
        glColor3f(0.2f, 0.55f, 0.2f);
    }
    
    glPushMatrix();
    glTranslatef(0, -0.375f, 0); 
    float roadW = 7.5f;
    float sidewalkW = 3.5f;
    float innerEdge = roadW + sidewalkW; 
    
    float texZStart = zStart / 8.0f;
    float texZEnd   = zEnd / 8.0f;
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f); 
    if (grassTexID != 0) {
        float texLen = outerEdge - innerEdge;
        
        glTexCoord2f(0.0f, texZStart); glVertex3f(-outerEdge, 0, zStart);
        glTexCoord2f(texLen / 4.0f, texZStart); glVertex3f(-innerEdge, 0, zStart);
        glTexCoord2f(texLen / 4.0f, texZEnd);   glVertex3f(-innerEdge, 0, zEnd);
        glTexCoord2f(0.0f, texZEnd);   glVertex3f(-outerEdge, 0, zEnd);
        
        glTexCoord2f(0.0f, texZStart); glVertex3f(innerEdge, 0, zStart);
        glTexCoord2f(texLen / 4.0f, texZStart); glVertex3f(outerEdge, 0, zStart);
        glTexCoord2f(texLen / 4.0f, texZEnd);   glVertex3f(outerEdge, 0, zEnd);
        glTexCoord2f(0.0f, texZEnd);   glVertex3f(innerEdge, 0, zEnd);
    } else {
        glVertex3f(-outerEdge, 0, zStart);     glVertex3f(-innerEdge, 0, zStart);
        glVertex3f(-innerEdge, 0, zEnd);       glVertex3f(-outerEdge, 0, zEnd);
        glVertex3f(innerEdge, 0, zStart);      glVertex3f(outerEdge, 0, zStart);
        glVertex3f(outerEdge, 0, zEnd);        glVertex3f(innerEdge, 0, zEnd);
    }
    glEnd();
    glPopMatrix();
    if (grassTexID != 0) glDisable(GL_TEXTURE_2D);
}

void drawTreeBackdrop() {
    if (bgTreeTexID == 0) return;

    float base = carPosZ - 50.0f; 
    float zStart = base; 
    float zEnd = base + 580.0f; 
    float outerEdge = 40.0f;    
    float wallHeight = 15.0f;   

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, bgTreeTexID);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); 

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f); 

    float texZStart = zStart / 12.0f;
    float texZEnd   = zEnd / 12.0f;

    glBegin(GL_QUADS);
    
    glTexCoord2f(texZStart, 1.0f); glVertex3f(-outerEdge, -0.375f, zStart);
    glTexCoord2f(texZEnd,   1.0f); glVertex3f(-outerEdge, -0.375f, zEnd);
    glTexCoord2f(texZEnd,   0.0f); glVertex3f(-outerEdge, wallHeight, zEnd);
    glTexCoord2f(texZStart, 0.0f); glVertex3f(-outerEdge, wallHeight, zStart);

    glTexCoord2f(texZStart, 1.0f); glVertex3f(outerEdge, -0.375f, zStart);
    glTexCoord2f(texZStart, 0.0f); glVertex3f(outerEdge, wallHeight, zStart);
    glTexCoord2f(texZEnd,   0.0f); glVertex3f(outerEdge, wallHeight, zEnd);
    glTexCoord2f(texZEnd,   1.0f); glVertex3f(outerEdge, -0.375f, zEnd);

    float frontEdge = outerEdge - 1.5f; 
    float frontHeightOffset = 0.5f;

    glTexCoord2f(texZStart, 1.0f); glVertex3f(-frontEdge, -0.375f + frontHeightOffset, zStart);
    glTexCoord2f(texZEnd,   1.0f); glVertex3f(-frontEdge, -0.375f + frontHeightOffset, zEnd);
    glTexCoord2f(texZEnd,   0.0f); glVertex3f(-frontEdge, wallHeight + frontHeightOffset, zEnd);
    glTexCoord2f(texZStart, 0.0f); glVertex3f(-frontEdge, wallHeight + frontHeightOffset, zStart);

    glTexCoord2f(texZStart, 1.0f); glVertex3f(frontEdge, -0.375f + frontHeightOffset, zStart);
    glTexCoord2f(texZStart, 0.0f); glVertex3f(frontEdge, wallHeight + frontHeightOffset, zStart);
    glTexCoord2f(texZEnd,   0.0f); glVertex3f(frontEdge, wallHeight + frontHeightOffset, zEnd);
    glTexCoord2f(texZEnd,   1.0f); glVertex3f(frontEdge, -0.375f + frontHeightOffset, zEnd);

    glEnd();
    
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}

void drawFinishLine() {
    float fz = FINISH_Z; int tiles = 14; float tw = 15.0f / tiles;
    for (int i = 0; i < tiles; i++) {
        bool white = (i % 2 == 0); glColor3f(white ? 1.0f : 0.0f, white ? 1.0f : 0.0f, white ? 1.0f : 0.0f);
        glPushMatrix(); glTranslatef(-7.5f + tw * (i + 0.5f), -0.29f, fz); glScalef(tw, 0.02f, 1.5f); glutSolidCube(1); glPopMatrix();
    }
    float tiang[][2] = { {-7.7f, 0}, {7.7f, 0} };
    for (int t = 0; t < 2; t++) { glColor3f(0.1f, 0.1f, 0.1f); glPushMatrix(); glTranslatef(tiang[t][0], 3.0f, fz); glScalef(0.2f, 6, 0.2f); glutSolidCube(1); glPopMatrix(); }
    for (int seg = 0; seg < 20; seg++) {
        float sx = -7.5f + seg * 0.75f; glColor3f(seg % 2 == 0 ? 0.9f : 1.0f, seg % 2 == 0 ? 0.1f : 1.0f, seg % 2 == 0 ? 0.1f : 1.0f);
        glPushMatrix(); glTranslatef(sx + 0.375f, 6.1f, fz); glScalef(0.75f, 0.4f, 0.15f); glutSolidCube(1); glPopMatrix();
    }
    glColor3f(0.9f, 0.85f, 0.1f);
    glPushMatrix(); glTranslatef(0, 5.85f, fz); glScalef(15.4f, 0.12f, 0.18f); glutSolidCube(1); glPopMatrix();
    glPushMatrix(); glTranslatef(0, 6.4f, fz);  glScalef(15.4f, 0.12f, 0.18f); glutSolidCube(1); glPopMatrix();
}

void drawWheel(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x, y, z); glRotatef(90, 0, 1, 0);
    glColor3f(0.1f, 0.1f, 0.1f); glutSolidTorus(0.12f, 0.28f, 16, 16);
    glColor3f(0.85f, 0.85f, 0.85f); glScalef(1, 1, 0.1f); glutSolidSphere(0.25f, 16, 16); glPopMatrix();
}

void drawCar() {
    glColor3f(0.8f, 0.0f, 0.0f);
    glPushMatrix(); glTranslatef(0.0f, 0.3f, 0.0f); glScalef(1.5f, 0.5f, 3.5f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.75f, -0.2f); glScalef(1.3f, 0.45f, 1.8f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.05f, 0.05f, 0.05f);
    glPushMatrix(); glTranslatef(0.0f, 0.75f, -0.2f); glScalef(1.32f, 0.35f, 1.6f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.75f, 0.68f); glScalef(1.2f, 0.35f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.75f, -1.08f); glScalef(1.2f, 0.35f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(0.95f, 0.95f, 0.6f); 
    float lp[] = { -0.5f, 0.5f };
    for (int i = 0; i < 2; i++) {
        glPushMatrix(); glTranslatef(lp[i], 0.4f, 1.76f); glScalef(0.3f, 0.2f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    }
    glColor3f(0.9f, 0.1f, 0.1f);
    for (int i = 0; i < 2; i++) {
        glPushMatrix(); glTranslatef(lp[i], 0.4f, -1.76f); glScalef(0.35f, 0.22f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    }
    glColor3f(0.15f, 0.15f, 0.15f);
    glPushMatrix(); glTranslatef(0.0f, 0.15f, 1.76f); glScalef(1.52f, 0.2f, 0.1f); glutSolidCube(1.0f); glPopMatrix();
    drawWheel(0.78f, 0.15f,  1.1f);
    drawWheel(-0.78f, 0.15f,  1.1f);
    drawWheel(0.78f, 0.15f, -1.1f);
    drawWheel(-0.78f, 0.15f, -1.1f);
}

void resetGame() {
    carPosX = 0.0f; carPosZ = 0.0f; carSpeed = 0.0f; gas = 100.0f; currentState = PLAYING;
    for (int i = 0; i < 256; i++) keys[i] = false;
    worldObjects.clear(); lastGeneratedZ = 60.0f; spawnLightThisChunk = true;
    rocks.clear();
    for (float z = 0; z < lastGeneratedZ; z += CHUNK_SIZE) generateChunk(z);
    generateJerrycans();
}

void drawHUD() {
    glMatrixMode(GL_PROJECTION); glPushMatrix(); glLoadIdentity(); gluOrtho2D(0, winW, 0, winH);
    glMatrixMode(GL_MODELVIEW); glPushMatrix(); glLoadIdentity(); glDisable(GL_LIGHTING); glDisable(GL_DEPTH_TEST);
    
    float bx = 20, by = 20, bw = 250, bh = 65; glColor4f(0.05f, 0.05f, 0.05f, 0.78f);
    glBegin(GL_QUADS); glVertex2f(bx, by); glVertex2f(bx + bw, by); glVertex2f(bx + bw, by + bh); glVertex2f(bx, by + bh); glEnd();
    glColor3f(0.5f, 0.5f, 0.5f); glLineWidth(1.5f); glBegin(GL_LINE_LOOP); glVertex2f(bx, by); glVertex2f(bx + bw, by); glVertex2f(bx + bw, by + bh); glVertex2f(bx, by + bh); glEnd();
    glColor3f(1, 1, 1); drawString2D(bx + 8, by + 40, "GAS");
    
    float barX = bx + 55, barY = by + 38, barW = 125, barH = 14; glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS); glVertex2f(barX, barY); glVertex2f(barX + barW, barY); glVertex2f(barX + barW, barY + barH); glVertex2f(barX, barY + barH); glEnd();
    float ratio = gas / 100.0f; float gr = (gas > 50) ? (1.0f - 2 * (1.0f - ratio)) : (2 * ratio); 
    float gg = (gas > 50) ? 1.0f : (2 * ratio);
    glColor3f(gr < 0 ? 0 : gr, gg > 1 ? 1 : gg, 0); glBegin(GL_QUADS); glVertex2f(barX, barY); glVertex2f(barX + barW * ratio, barY); glVertex2f(barX + barW * ratio, barY + barH); glVertex2f(barX, barY + barH); glEnd();
    char buf[64]; snprintf(buf, sizeof(buf), "%.0f%%", gas); glColor3f(1, 1, 1); drawString2D(barX + barW + 5, barY, buf);
    if (currentState == GAME_OVER && gas <= 0) { glColor3f(1.0f, 0.25f, 0.25f); drawString2D(bx + 8, by + 14, "OUT OF GAS!"); }
    else { snprintf(buf, sizeof(buf), "Speed: %.1f", carSpeed * 200.0f); glColor3f(0.75f, 0.75f, 0.75f); drawString2D(bx + 8, by + 14, buf); }

    void* defaultFont = GLUT_BITMAP_HELVETICA_18;
    int tw; 

    if (currentState == GAME_OVER) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f); 
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(winW, 0); glVertex2f(winW, winH); glVertex2f(0, winH); glEnd();
        
        float pw = 420, ph = 220; float px = (winW - pw) / 2, py = (winH - ph) / 2;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glBegin(GL_QUADS); glVertex2f(px, py); glVertex2f(px + pw, py); glVertex2f(px + pw, py + ph); glVertex2f(px, py + ph); glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f); glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP); glVertex2f(px, py); glVertex2f(px + pw, py); glVertex2f(px + pw, py + ph); glVertex2f(px, py + ph); glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f);
        const char* tGameOver = "GAME OVER";
        tw = getTextWidth(tGameOver, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 50, tGameOver, defaultFont);

        const char* tFuel = "You ran out of fuel!";
        tw = getTextWidth(tFuel, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 85, tFuel, defaultFont);

        snprintf(buf, sizeof(buf), "Distance Travelled: %.0f m", carPosZ);
        tw = getTextWidth(buf, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 125, buf, defaultFont);

        snprintf(buf, sizeof(buf), "Remaining to finish: %.0f m", FINISH_Z - carPosZ);
        tw = getTextWidth(buf, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 155, buf, defaultFont);

        const char* tRetry = "Press R to retry";
        tw = getTextWidth(tRetry, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + 30, tRetry, defaultFont);
    }

    if (currentState == GAME_FINISHED) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f); 
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(winW, 0); glVertex2f(winW, winH); glVertex2f(0, winH); glEnd();
        
        float pw = 420, ph = 220; float px = (winW - pw) / 2, py = (winH - ph) / 2;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glBegin(GL_QUADS); glVertex2f(px, py); glVertex2f(px + pw, py); glVertex2f(px + pw, py + ph); glVertex2f(px, py + ph); glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f); glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP); glVertex2f(px, py); glVertex2f(px + pw, py); glVertex2f(px + pw, py + ph); glVertex2f(px, py + ph); glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f);
        const char* tCongrats = "CONGRATULATION!";
        tw = getTextWidth(tCongrats, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 50, tCongrats, defaultFont);

        const char* tFinish = "You Finish The Game";
        tw = getTextWidth(tFinish, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 95, tFinish, defaultFont);

        snprintf(buf, sizeof(buf), "Final Distance: %.0f m", carPosZ);
        tw = getTextWidth(buf, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + ph - 135, buf, defaultFont);

        const char* tAgain = "Press R to play again";
        tw = getTextWidth(tAgain, defaultFont);
        drawString2D(px + (pw - tw) / 2, py + 40, tAgain, defaultFont);
    }
    
    glEnable(GL_DEPTH_TEST); glEnable(GL_LIGHTING); glMatrixMode(GL_PROJECTION); glPopMatrix(); glMatrixMode(GL_MODELVIEW); glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glLoadIdentity();
    float rad  = camAngleX * 3.14159f / 180.0f;
    float eyeY = camOffsetY + (camDistance * sinf(rad)); 
    float eyeZ = carPosZ - (camDistance * cosf(rad));   
    gluLookAt(carPosX, eyeY, eyeZ, carPosX, 0.6f, carPosZ + 4.0f, 0, 1, 0);
    
    drawSkybox();       
    updateWorld();
    
    drawGround2(); 
    drawGround1(); 
    
    drawTreeBackdrop();
    
    for (size_t i = 0; i < worldObjects.size(); i++) {
        const WorldObject& o = worldObjects[i]; 
        if (o.type < 5) drawTree(o); 
        else if (o.type == 10) drawStreetLight(o.x, o.z); 
        else drawBuilding(o);
    }
    drawFinishLine();

    // Gambar batu
    for (size_t i = 0; i < rocks.size(); i++)
        if (!rocks[i].hit) drawRock(rocks[i].x, rocks[i].z);

    float bob = sinf(jerryBobTime) * 0.12f;
    for (size_t i = 0; i < jerrycans.size(); i++) if (!jerrycans[i].collected) drawJerrycan(jerrycans[i].x, jerrycans[i].z, bob);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix(); glTranslatef(carPosX, 0, carPosZ); drawCar(); glPopMatrix();
    glPopAttrib();
    drawHUD(); glutSwapBuffers();
}

void reshape(int w, int h) {
    winW = w; winH = (h == 0) ? 1 : h; glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(55, (float)w / h, 0.3f, 600); glMatrixMode(GL_MODELVIEW);
}

void updateTimer(int value) {
    jerryBobTime += 0.05f;
    if (currentState == PLAYING) {
        if ((keys['w'] || keys['W']) && gas > 0) {
            carSpeed += ACCEL; if (carSpeed > MAX_SPEED) carSpeed = MAX_SPEED; gas -= GAS_BURN; 
        } else if (keys['s'] || keys['S']) {
            carSpeed -= BRAKE_DECEL; if (carSpeed < 0.0f) carSpeed = 0.0f; 
        } else {
            if (carSpeed > 0.0f) { carSpeed -= FRICTION; if (carSpeed < 0.0f) carSpeed = 0.0f; }
        }
        if (!(keys['w'] || keys['W']) && gas > 0) { if (carSpeed > 0.0f) gas -= GAS_IDLE; }
        if (gas < 0) gas = 0;
        carPosZ += carSpeed;
        if (carSpeed > 0.01f) {
            if (keys['a'] || keys['A']) carPosX += STEER_SPEED;
            if (keys['d'] || keys['D']) carPosX -= STEER_SPEED;
        }
        if (carPosX > 6.2f)  carPosX = 6.2f;  
        if (carPosX < -6.2f) carPosX = -6.2f; 

        // Cek tabrakan jerrycan
        for (size_t i = 0; i < jerrycans.size(); i++) {
            if (!jerrycans[i].collected) {
                float ddx = jerrycans[i].x - carPosX;
                float ddz = jerrycans[i].z - carPosZ;
                float dist = sqrtf(ddx * ddx + ddz * ddz);
                if (dist < JERRY_PICKUP_R) {
                    jerrycans[i].collected = true;
                    gas += 35.0f; if (gas > 100.0f) gas = 100.0f;
                }
            }
        }

        // Cek tabrakan batu — kurangi 25% dari gas saat ini
        for (size_t i = 0; i < rocks.size(); i++) {
            if (!rocks[i].hit) {
                float rdx = rocks[i].x - carPosX;
                float rdz = rocks[i].z - carPosZ;
                float dist = sqrtf(rdx * rdx + rdz * rdz);
                if (dist < ROCK_HIT_R) {
                    rocks[i].hit = true;
                    gas -= 25.0f;   // kurangi flat 25 dari total 100
                    if (gas < 0.0f) gas = 0.0f;
                }
            }
        }

        if (gas <= 0 && carSpeed <= 0.0f)  currentState = GAME_OVER;
        if (carPosZ >= FINISH_Z) { currentState = GAME_FINISHED; carSpeed = 0.0f; }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateTimer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    keys[key] = true;
    if (key >= 'a' && key <= 'z') keys[key - 32] = true;
    if (key >= 'A' && key <= 'Z') keys[key + 32] = true;
    if ((key == 'r' || key == 'R') && (currentState == GAME_OVER || currentState == GAME_FINISHED)) {
        resetGame(); glutPostRedisplay(); return;
    }
    switch (key) {
        case 'q': case 'Q': camDistance -= 0.5f; break;
        case 'e': case 'E': camDistance += 0.5f; break;
    }
    if (camDistance < 2.0f) camDistance = 2.0f;
    glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y) {
    keys[key] = false;
    if (key >= 'a' && key <= 'z') keys[key - 32] = false;
    if (key >= 'A' && key <= 'Z') keys[key + 32] = false;
}

void setup() {
    glEnable(GL_DEPTH_TEST); glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glShadeModel(GL_SMOOTH); glEnable(GL_NORMALIZE);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glClearColor(0.4f, 0.72f, 1.0f, 1.0f);
    GLfloat lpos[] = { 10, 15, 10, 0 }; glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    GLfloat amb[] = { 0.38f, 0.38f, 0.38f, 1 }; glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
    
    GLfloat spec[] = { 1, 1, 1, 1 }; GLfloat shin[] = { 50 }; 
    glMaterialfv(GL_FRONT, GL_SPECULAR, spec); glMaterialfv(GL_FRONT, GL_SHININESS, shin);
    
    loadTextureFromImage("Langit.bmp", skyTexID);
    loadTextureWithBlackAsAlpha("BCpohon.bmp", bgTreeTexID);
    loadTextureFromImage("Rumput.bmp", grassTexID);
    loadTextureFromImage("Aspal GTI.bmp", asphaltTexID);
    loadTextureFromImage("BuildingGlass.bmp", glassTexID);
    loadTextureFromImage("BuildingWarehouse.bmp", warehouseTexID);
    loadTextureFromImage("BuildingBox.bmp", boxTexID);
    
    for (float z = 0; z < lastGeneratedZ; z += CHUNK_SIZE) generateChunk(z);
    generateJerrycans();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("Petrol Run");
    setup();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, updateTimer, 0);
    glutMainLoop();
    return 0;
}