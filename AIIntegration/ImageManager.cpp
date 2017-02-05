//
// Created by Sebastían on 9/11/2016.
//
#include "ImageManager.h"

Image * ImageManager::loadImage(string path) {
    ifstream stream;
    stream.open(path, std::ios::binary);

    if (stream.fail()) {
        return nullptr;
    }

    string header = "";
    stream >> header;

    if (strcmp(header.c_str(), "P6") != 0) {
        return nullptr;
    }

    int width, height, unused;
    stream >> width >> height >> unused;
    stream.ignore(256, '\n');

    Image * image = new Image(width, height);
    unsigned char colorData[3];
    int red, green, blue;

    for (int i = 0; i < width * height; ++ i) {
        stream.read(reinterpret_cast<char *>(colorData), 3);
        red = colorData[0];
        green = colorData[1];
        blue = colorData[2];

        image -> setPixel(i, red, green, blue);
    }
    stream.close();
    return image;
}

void ImageManager::saveImage(Image * image, string path) {
    ofstream out(path, std::ios::binary);
    int width = image->getWidth();
    int height = image->getHeight();
    out << "P6\n" << width << " " << height << "\n255\n";
    unsigned char rr, gg, bb;
    for (int y = 0; y < height * width; y ++) {
        rr = static_cast<unsigned char>(image->getRed(y));
        gg = static_cast<unsigned char>(image->getGreen(y));
        bb = static_cast<unsigned char>(image->getBlue(y));

        out << rr << gg << bb;
    }
    out.close();
}