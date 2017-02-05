//
// Created by Sebastían on 8/11/2016.
//

#include "Edge.h"

bool Edge::isConnected(Vertex * begin, Vertex * end) {
    return begin -> getIndex() == getBegin() -> getIndex() && end -> getIndex() == getEnd() -> getIndex();
}

Vertex * Edge::getBegin() {
    return begin;
}

Vertex * Edge::getEnd() {
    return end;
}

void Edge::setWeight(float newWeight) {
    weight = newWeight;
}

float Edge::getWeight() {
    return weight;
}