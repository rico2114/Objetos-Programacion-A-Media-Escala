//
// Created by Sebastían on 9/11/2016.
//

#include "CorpusLoader.h"
#include "ImageManager.h"
#include "EigenVectorCalculator.h"
#include <sstream>

#define intToString( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

vector<vector<float>> * CorpusLoader::loadCorpus(string path, string filePrefix, int inclusiveInitialIndex, int inclusiveLastIndex, int inclusiveMaxNumberOfSamples) {
    vector<vector<float>> * result = new vector<vector<float>>();
    vector<int> cuts = {0, 1, 2, 4, 6, 8, 9};

    for (int x = 0; x <= inclusiveMaxNumberOfSamples; x++) {
        for (int i = inclusiveInitialIndex; i <= inclusiveLastIndex; i++) {
            string name = filePrefix;
            string _path = path;
            string dir = _path.append(name.append(intToString(i)).append("_").append(intToString(x)).append(".ppm"));
            result -> push_back(*(EigenVectorCalculator::calculateEigenVector(dir, cuts)));
        }
    }
    return result;
}