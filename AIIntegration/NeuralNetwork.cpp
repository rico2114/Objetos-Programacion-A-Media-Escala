//
// Created by Sebastían on 8/11/2016.
//

#include "NeuralNetwork.h"

float NeuralNetwork::nextRandom() {
    static std::default_random_engine engine;
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        engine.seed((unsigned int) time(NULL));
    }
    static std::uniform_real_distribution<> distribution(0, 1);
    return distribution(engine);
}

float NeuralNetwork::sigmoid(float value) {
    return (1 / (1 + exp(-value)));
}

void NeuralNetwork::print() {
    for (Vertex * vertex : initialAndMiddleLayer) {
        cout << "El vertice: " << vertex -> getIndex() << " tiene un valor de: " << vertex -> getValue() << " y un bias de: " << vertex -> getBiasWeight() << endl;
        cout << "Ademas tiene edges: " << endl;
        for (Edge * edge : vertex -> getEdges()) {
            cout << "edge inicio: " << edge -> getBegin() -> getIndex() << " ; edge final: " << edge -> getEnd() -> getIndex() << " ; peso: " << edge -> getWeight() << endl;
        }
    }
}

NeuralNetwork* NeuralNetwork::load(string path) {
    ifstream stream(path);
    NeuralNetwork * network = new NeuralNetwork();
    int initialLayerSize = 0;
    stream >> initialLayerSize;
    int index;
    float value, biasWeight;
    vector<Vertex *> helper;
    for (int i = 0; i < initialLayerSize; i ++) {
        stream >> index;
        stream >> value;
        stream >> biasWeight;
        Vertex * cached = new Vertex(index, value, biasWeight);
        network -> initialAndMiddleLayer.push_back(cached);
        helper.push_back(cached);
    }
    int finalLayer = 0;
    stream >> finalLayer;

    for (int i = 0; i < finalLayer; i ++) {
        stream >> index;
        stream >> value;
        stream >> biasWeight;
        Vertex * cached = new Vertex(index, value, biasWeight);
        network -> finalLayer.push_back(cached);
        helper.push_back(cached);
    }
    int edgesSize = 0;
    stream >> edgesSize;
    int beginIndex, endIndex;
    float weight;
    Vertex * beginVertex;
    Vertex * endVertex;

    for (int i = 0; i < edgesSize; i ++) {
        stream >> beginIndex;
        stream >> endIndex;
        stream >> weight;

        for (Vertex * vertex : helper) {
            if (vertex -> getIndex() == beginIndex) {
                beginVertex = vertex;
            }
            if (vertex -> getIndex() == endIndex) {
                endVertex = vertex;
            }
        }
        Edge * edge = new Edge(beginVertex, endVertex, weight);
        beginVertex -> attachEdge(edge);
        endVertex -> attachEdge(edge);
    }
    stream.close();
    return network;
}

void NeuralNetwork::save(string path) {
    ofstream stream(path);
    // initial layer size and save
    int initialLayerSize = initialAndMiddleLayer.size();
    Vertex * vertex;
    stream << initialLayerSize << endl;
    for (int i = 0; i < initialLayerSize; i ++) {
        vertex = initialAndMiddleLayer[i];
        stream << vertex -> getIndex() << endl;
        stream << vertex -> getValue() << endl;
        stream << vertex -> getBiasWeight() << endl;
    }
    // final layer size and save
    int finalLayerSize = finalLayer.size();
    stream << finalLayerSize << endl;
    for (int i = 0; i < finalLayerSize; i ++) {
        vertex = finalLayer[i];
        stream << vertex -> getIndex() << endl;
        stream << vertex -> getValue() << endl;
        stream << vertex -> getBiasWeight() << endl;
    }
    // Add all edges
    vector<Edge *> allEdges;
    for (Vertex * vertexRepr : initialAndMiddleLayer) {
        for (Edge * edge : vertexRepr -> getEdges()) {
            allEdges.push_back(edge);
        }
    }
    int edgesSize = allEdges.size();
    stream << edgesSize << endl;
    Edge * edge;
    for (int i = 0; i < edgesSize; i ++) {
        edge = allEdges[i];
        stream << edge->getBegin()->getIndex() << endl;
        stream << edge->getEnd()->getIndex() << endl;
        stream << edge ->getWeight() << endl;
    }
    stream.close();
}

void NeuralNetwork::create(int inputs, int outputs) {
    // First we crate the final layer
    int cachedIndex = 0;
    for (int i = 0; i < outputs; i ++) {
        finalLayer.push_back(new Vertex(cachedIndex ++, nextRandom(), nextRandom()));
    }
    // Then we connect it with the initial layer
    for (int i = 0; i < inputs; i ++) {
        Vertex * vertex = new Vertex(cachedIndex ++, nextRandom(), nextRandom());
        for (int o = 0; o < outputs; o ++) {
            Edge * edge = new Edge(vertex, finalLayer[o], nextRandom());
            vertex -> attachEdge(edge);
            finalLayer[o] -> attachEdge(edge);
        }
        initialAndMiddleLayer.push_back(vertex);
    }
}

float * NeuralNetwork::calculateOutput() {
    float * data = new float[finalLayer.size()];
    int size = finalLayer.size();
    for (int i = 0; i < size; i ++) {
        finalLayer[i] -> calculateOutput();
        data[i] = finalLayer[i] -> getValue();
    }
    return data;
}

void NeuralNetwork::adjustWages(float *goodOutput) {
    int size = finalLayer.size();
    for (int i = 0; i < size; i ++) {
        float error = goodOutput[i] - finalLayer[i]->getValue();
        finalLayer[i]->adjustWeight(error);
    }
}

void NeuralNetwork::setInputs(float *inputs) {
    int size = initialAndMiddleLayer.size();
    for (int i = 0; i < size; i ++) {
        initialAndMiddleLayer[i]->setValue(inputs[i]);
    }
}
