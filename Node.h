#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int val, Node* link = nullptr);
    int getData() const;
    void setData(int val);
    Node* getNext() const;
    void setNext(Node* node);


    int data;
    Node* link;
};

#endif
