//
// Created by Sebastían on 8/11/2016.
//

#ifndef AIDEFINITIVA_VERTEX_H
#define AIDEFINITIVA_VERTEX_H

#include <vector>
#include <iostream>

#include "Edge.h"

class Edge;
using std::vector;
using std::cout;
using std::endl;

class Vertex {

    /**
     * Represents all the edges in the vertex
     */
    vector<Edge *> edges;

    /**
     * Represents the index of the vertex used to identify them individually
     */
    int index;

    /**
     * Represents the value of the vertex
     */
    float value;

    /**
     * Represents the bias weight of the vertex
     */
    float biasWeight;

public:

    /**
     * Constructs the vertex based on the index value and bias
     * @param _index    the index of the vertex
     * @param _value    the value of the vertex
     * @param _bias the bias of the vertex
     */
    Vertex(int _index, float _value, float _bias) : index(_index), value(_value), biasWeight(_bias) {}

    /**
     * Attempts to attach a new edge into the edges vector
     * @param edge  the new edge to be added
     */
    void attachEdge(Edge * edge);

    /**
     * Prints the vertex with its respective edges
     */
    void print();

    /**
     * Calculates the output of the vertex
     */
    void calculateOutput();

    /**
     * Adjusts its local bias weight based on the error
     * @param error the error
     */
    void adjustWeight(float error);

    /**
     * Gets all the edges of the vertex
     * @return  the edges
     */
    vector<Edge *> getEdges();

    /**
     * Iterates through the edges to find the edge with the desired initial and final vertexs
     * @param initial   the initial vertex
     * @param final the final vertex
     * @return  the edge
     */
    Edge * getEdge(Vertex * initial, Vertex * final);

    /**
     * Gets the index of the vertex
     * @return the index
     */
    int getIndex();

    /**
     * Sets the value of the new vertex
     * @param newValue  the new value
     */
    void setValue(float newValue);

    /**
     * Gets the value of the vertex
     * @return  the value
     */
    float getValue();

    /**
     * Gets the bias weight of the vertex
     * @return  the bias weight
     */
    float getBiasWeight();
};

#endif //AIDEFINITIVA_VERTEX_H
