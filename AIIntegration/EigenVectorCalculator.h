//
// Created by Sebastían on 9/11/2016.
//

#ifndef AIDEFINITIVA_EIGENVECTORCALCULATOR_H
#define AIDEFINITIVA_EIGENVECTORCALCULATOR_H
#include <vector>
#include <string>

using std::string;
using std::vector;

class EigenVectorCalculator {
    /**
     * Privatices the constructing class to avoid initializing (this is a static class)
     */
    EigenVectorCalculator() {}
public:
    /**
     * Calculates the eigen vectors of the image based on the cuts
     * @param path  the dir of the image
     * @param cuts  the transversal cuts from the image (horizontal and vertical)
     * @return a vector with the respective eigen vectors
     */
    static vector<float> * calculateEigenVector(string path, vector<int> cuts);
};


#endif //AIDEFINITIVA_EIGENVECTORCALCULATOR_H
