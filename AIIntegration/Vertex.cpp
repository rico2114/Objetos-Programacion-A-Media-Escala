//
// Created by Sebastían on 8/11/2016.
//

#include "Vertex.h"
#include "NeuralNetwork.h"

int Vertex::getIndex() {
    return index;
}

void Vertex::calculateOutput() {
    static const float BIAS = 1;

    Vertex * initial;
    int edgesSize = edges.size();
    float sum = 0;
    for (int i = 0; i < edgesSize; i ++) {
        initial = edges[i] -> getBegin();
        sum += initial -> getValue() * edges[i] -> getWeight();
    }
    sum += BIAS * biasWeight;
    setValue(NeuralNetwork::sigmoid(sum));
}

void Vertex::adjustWeight(float error) {
    static const float LEARNING_RATIO = 0.1;
    static const float BIAS = 1;

    int edgesSize = edges.size();
    float weight = 0;
    Vertex * input;
    for (int i = 0; i < edgesSize; i ++) {
        weight = edges[i] -> getWeight();
        input = edges[i] -> getBegin();
        weight += LEARNING_RATIO * error * (input -> getValue());
        edges[i] -> setWeight(weight);
    }
    biasWeight += LEARNING_RATIO * error * BIAS;
}

void Vertex::attachEdge(Edge * edge) {
    edges.push_back(edge);
}

void Vertex::print() {
    cout << "El vertice con indice: " << index << " tiene valor: " << value << " y aristas: " << endl;
    for (Edge * edge : edges) {
        cout << "peso: " << edge -> getWeight() << ", ";
    }
    cout << endl;
}

Edge * Vertex::getEdge(Vertex * initial, Vertex * final) {
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i] -> isConnected(initial, final))
            return edges[i];
    }
    return nullptr;
}

vector<Edge *> Vertex::getEdges() {
    return edges;
}

void Vertex::setValue(float newValue) {
    value = newValue;
}

float Vertex::getValue() {
    return value;
}

float Vertex::getBiasWeight() {
    return biasWeight;
}