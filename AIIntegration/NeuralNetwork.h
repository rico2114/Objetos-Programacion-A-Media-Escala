//
// Created by Sebastían on 8/11/2016.
//

#ifndef AIDEFINITIVA_NEURALNETWORK_H
#define AIDEFINITIVA_NEURALNETWORK_H
#include <vector>
#include "Vertex.h"
#include <iomanip>
#include <random>
#include <cmath>
#include <string>
#include <fstream>

using std::exp;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fixed;
using std::showpoint;
using std::setprecision;

class NeuralNetwork {

    /**
     * Represents the initial and middle layer neurons
     */
    vector<Vertex *> initialAndMiddleLayer;

    /**
     * Represents the final layer neurons
     */
    vector<Vertex *> finalLayer;

public:
    /**
     * Calculates the next random (between 0 and 1)
     * @return  the next random
     */
    static float nextRandom();

    /**
     * Calculates the sigmoid of a value
     * @param value
     * @return  the sigmoid value
     */
    static float sigmoid(float value);

    /**
     * Attempts to save the neural network with its layers
     * @param path  the path to the directory of the save
     */
    void save(string path);

    /**
     * Attempts to load a neural network
     * @param path  the path to the file
     * @return  an instance of a new neural network
     */
    static NeuralNetwork * load(string path);

    /**
     * Creates a neural network based on the inputs and outputs (note that this has to be called when we are NOT loading)
     * @param inputs    the number of inputs
     * @param outputs   the number of outputs
     */
    void create(int inputs, int outputs);

    /**
     * Adjust the wages of the neural network (backpropagation) based on a good output
     * @param goodOutput    what the neural network should display
     */
    void adjustWages(float *goodOutput);

    /**
     * Calculates the output of the neural network (feed forward)
     * @return  a float of data
     */
    float * calculateOutput();

    /**
     * Sets the inputs of the neural network
     * @param inputs    the input values
     */
    void setInputs(float * inputs);

    /**
     * Prints the neural network (just for testing purposes)
     */
    void print();
};


#endif //AIDEFINITIVA_NEURALNETWORK_H
