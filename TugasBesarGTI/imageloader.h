#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <GL/glut.h>

class Image {
public:
    Image();
    ~Image();
    bool loadBMP(const char* filename);
    unsigned char* getPixels() const;
    int getWidth() const;
    int getHeight() const;

private:
    unsigned char* pixels;
    int width;
    int height;
};

#endif
