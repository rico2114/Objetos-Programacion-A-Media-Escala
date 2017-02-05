//
// Created by Sebastían on 4/09/2016.
//

#include "Image.h"

Image* Image::subImage(int initialX, int initialY, int width, int height) {
    int endingY = initialY + height;
    int endingX = initialX + width;
    if (endingX > getWidth() || endingY > getHeight()) {
        return nullptr;
    }

    int color, counter = 0;
    Image * image = new Image(width, height);
    for (int y = initialY; y < endingY; y++) {
        for (int x = initialX; x < endingX; x++) {
            color = getPixel(convertPoints(x, y));
            image->setPixel(counter, color);
            counter ++;
        }
    }
    return image;
}

Image* Image::copy() {
    Image * result = new Image(width, height);
    for (int i = 0; i < width * height; i ++) {
        result->setPixel(i, pixels[i]);
    }
    return result;
}

int Image::convertPoints(int x, int y) {
    return (y * width) + x;
}

void Image::setPixel(int id, int red, int green, int blue) {
    pixels[id] = ((blue & 0xff) << 16)| ((green & 0xff) << 8) | (red & 0xff);
}

void Image::setPixel(int id, int color) {
    pixels[id] = color;
}

int Image::getPixel(int coordinate) {
    return pixels[coordinate];
}

void Image::convertToBlackAndWhite(int delta) {
    for (int i = 0; i < width * height; i ++) {
        if (getRed(i) < delta && getBlue(i) < delta && getGreen(i) < delta) {
            setPixel(i, 0, 0, 0);
        } else {
            setPixel(i, 255, 255, 255);
        }
    }
}

int Image::getRed(int id) {
    return (pixels[id] & 0xff);
}

int Image::getGreen(int id) {
    return ((pixels[id] >> 8) & 0xff);
}

int Image::getBlue(int id) {
    return ((pixels[id] >> 16) & 0xff);
}

bool Image::isWhite(int id) {
    return getRed(id) == 255 && getGreen(id) == 255 && getBlue(id) == 255;
}

int Image::getMaximumPixel() {
    int position = 0;
    int max = pixels[0];
    for(int i = 1; i < width * height; i++) {
        if(pixels[i] > max) {
            max = pixels[i];
            position = i;
        }
    }
    return position;
}

int Image::getWidth() {
    return width;
}

int Image::getHeight() {
    return height;
}