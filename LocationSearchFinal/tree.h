#ifndef TREE_H
#define TREE_H

#include "address.h"

class Tree {
private:
    class Node {
    public:
        Address data;
        Node* left;
        Node* right;
        Node(const Address& address) : data(address), left(nullptr), right(nullptr) {}
    };

    Node* root;
    void insertRecursive(Node*& current, const Address& address);
    bool searchRecursive(Node* current, const Address& address) const;
    Address searchRecursiveDetails(Node* current, const Address& address) const;

public:
    Tree();
    ~Tree();
    void insert(const Address& address);
    bool search(const Address& address) const;
    Address retrieveDetails(const Address& address) const;
};

#endif