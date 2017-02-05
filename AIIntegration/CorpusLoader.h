//
// Created by Sebastían on 9/11/2016.
//

#ifndef AIDEFINITIVA_CORPUSLOADER_H
#define AIDEFINITIVA_CORPUSLOADER_H

#include <vector>
#include <string>

using std::string;
using std::vector;

class CorpusLoader {
    /**
     * Privatices the constructing class to avoid initializing (this is a static class)
     */
    CorpusLoader() {}
public:

    /**
     * A static function used to load the corpus eigen vectors (caracteristic vectors)
     * @param path  the path to the corpus
     * @param filePrefix    the file prefix (every file is named like "image")
     * @param inclusiveInitialIndex the inclusive initial iterator index value
     * @param inclusiveLastIndex    the inclusive final iterator index value
     * @param inclusiveMaxNumberOfSamples   the inclusive maximum samples
     * @return  a vector of vectors represeting the eigen vectors of every image in between the inclusive initial index and the last index
     */
    static vector<vector<float>> * loadCorpus(string path, string filePrefix, int inclusiveInitialIndex, int inclusiveLastIndex, int inclusiveMaxNumberOfSamples);
};


#endif //AIDEFINITIVA_CORPUSLOADER_H
