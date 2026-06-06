#include "imageloader.h"
#include <cstdio>
#include <cstdlib>

Image::Image() : pixels(NULL), width(0), height(0) {
}

Image::~Image() {
    if (pixels) {
        delete[] pixels;
    }
}

bool Image::loadBMP(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return false;

    unsigned char header[54];
    fread(header, 1, 54, file);
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(file);
        return false;
    }

    width = *(int*)&header[18];
    height = *(int*)&header[22];
    int dataOffset = *(int*)&header[10];

    int rowSize = (width * 3 + 3) & ~3;
    int imageSize = rowSize * height;

    unsigned char* rawData = new unsigned char[imageSize];
    fseek(file, dataOffset, SEEK_SET);
    fread(rawData, 1, imageSize, file);
    fclose(file);

    pixels = new unsigned char[width * height * 3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int bgrIndex = y * rowSize + x * 3;
            int rgbIndex = (height - y - 1) * width * 3 + x * 3;
            pixels[rgbIndex + 0] = rawData[bgrIndex + 2]; // R
            pixels[rgbIndex + 1] = rawData[bgrIndex + 1]; // G
            pixels[rgbIndex + 2] = rawData[bgrIndex + 0]; // B
        }
    }
    delete[] rawData;
    return true;
}

unsigned char* Image::getPixels() const {
    return pixels;
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}
