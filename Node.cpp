#include "Node.h"

Node::Node(int val, Node* next) : data(val), link(next) {}

int Node::getData() const {
    return data;
}

void Node::setData(int val) {
    data = val;
}

Node* Node::getNext() const {
    return link;
}

void Node::setNext(Node* node) {
    link = node;
}
