//
// Created by Sebastían on 8/11/2016.
//

#ifndef AIDEFINITIVA_EDGE_H
#define AIDEFINITIVA_EDGE_H
#include "Vertex.h"
class Vertex;

class Edge {
    /**
     * Represents the begining vertex (conection from)
     */
    Vertex * begin;

    /**
     * Represents the ending vertex (connected to)
     */
    Vertex * end;

    /**
     * Represents the weight of th edge
     */
    float weight;
public:

    /**
     * Constructs an edge with the begining vertex ending vertex and weight
     * @param _begin    the begining vertex
     * @param _end  the ending vertex
     * @param _weight   the weight of the edge
     */
    Edge(Vertex * _begin, Vertex * _end, float _weight) : begin(_begin), end(_end), weight(_weight) { }

    /**
     * Checks if whether or not the <code> begin </code> is connected with the vertex <code> end </code>
     * @param begin the begining vertex
     * @param end   the ending vertex
     * @return  true if it is connected false if is not
     */
    bool isConnected(Vertex * begin, Vertex * end);

    /**
     * Returns the initial vertex
     * @return  the initial vertex
     */
    Vertex * getBegin();

    /**
     * Returns the ending vertex
     * @return  the ending vertex
     */
    Vertex * getEnd();

    /**
     * Sets the weight of the edge
     * @param newWeight the new weight
     */
    void setWeight(float newWeight);

    /**
     * Gets the weight of the edge
     * @return  the weight
     */
    float getWeight();
};


#endif //AIDEFINITIVA_EDGE_H
