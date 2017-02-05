//
// Created by Sebastían on 9/11/2016.
//

#include "EigenVectorCalculator.h"
#include "Image.h"
#include "ImageManager.h"

vector<float> * EigenVectorCalculator::calculateEigenVector(string path, vector<int> cuts) {
    Image * image = ImageManager::loadImage(path);
    vector<float> * result = new vector<float>();
    int blackColor = 0;

    if (image == nullptr) {
        return nullptr;
    }

    for (int i : cuts) {
        int xCount = 0;
        for (int width = 0; width < image->getWidth(); width++) {
            if (image->getPixel(image->convertPoints(width, i)) != blackColor) {
                xCount++;
            }
        }
        result -> push_back(xCount);
    }
    for (int i : cuts) {
        int yCount = 0;
        for (int height = 0; height < image->getHeight(); height++) {
            if (image->getPixel(image->convertPoints(i, height)) != blackColor) {
                yCount++;
            }
        }
        result -> push_back(yCount);
    }
    delete(image);
    return result;
}
