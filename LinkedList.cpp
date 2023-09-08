#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    if (len == 0) {
        //let head be a new pointer
        head = nullptr;
    } else {
        head = new Node(array[0]);
        Node* node_n = head;
        for (int i = 1; i < len; i++) {
            node_n->link = new Node(array[i]);
            node_n = node_n->link;
        }
    }
}

LinkedList::~LinkedList() {
    Node* node_n = head;
    while (node_n != nullptr) {
        Node* temp = node_n;
        node_n = node_n->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || head == nullptr) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* node_n = head;
        int count = 1;
        while (count < pos-1 && node_n->link != nullptr) {
            node_n = node_n->link;
            count++;
        }
        newNode->link = node_n->link;
        node_n->link = newNode;
    }
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr) {
        return false;
    }
    if (pos <= 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
    } else {
        Node* node_n = head;
        int count = 1;
        while (count < pos-1 && node_n->link != nullptr) {
            node_n = node_n->link;
            count++;
        }
        if (node_n->link == nullptr) {
            return false;
        }
        Node* temp = node_n->link;
        node_n->link = temp->link;
        delete temp;
    }
    return true;
}

int LinkedList::get(int pos) {
    if (head == nullptr) {
        return std::numeric_limits<int>::max();
    }
    Node* node_n = head;
    int count = 1;
    while (count < pos && node_n != nullptr) {
        node_n = node_n->link;
        count++;
    }
    if (node_n == nullptr) {
        return std::numeric_limits<int>::max();
    }
    return node_n->data;
}

int LinkedList::search(int target) {
    Node* node_n = head;
    int count = 1;
    while (node_n != nullptr) {
        if (node_n->data == target) {
            return count;
        }
        node_n = node_n->link;
        count++;
    }
    return -1;
}

void LinkedList::printList() {
    if (head == nullptr) {
        return;
    }
    std::cout << "[" << head->data;
    Node* node_n = head->link;
    while (node_n != nullptr) {
        std::cout << " " << node_n->data;
        node_n = node_n->link;
    }
    std::cout << "]" << std::endl;
}
