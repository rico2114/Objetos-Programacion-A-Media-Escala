//
// Created by Sebastían on 9/11/2016.
//

#ifndef AIDEFINITIVA_IMAGEMANAGER_H
#define AIDEFINITIVA_IMAGEMANAGER_H

#include <string>
#include "Image.h"
#include <fstream>
#include <cstring>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::string;

class ImageManager {
    /**
     * Privatices the constructing class to avoid initializing (this is a static class)
     */
    ImageManager() {}
public:

    /**
     * Loads the image from a desired directory <code> path </code> note that this can only read .ppm formats
     * @param path  the path of the image
     * @return  the image instance
     */
    static Image * loadImage(string path);

    /**
     * Saves the image into a desired path (into a ppm format)
     * @param image the image instance
     * @param path  the desired path
     */
    static void saveImage(Image * image, string path);
};


#endif //AIDEFINITIVA_IMAGEMANAGER_H
