#include "tree.h"

//constructor
Tree::Tree() {
    root = nullptr;
}

//destructor
Tree::~Tree() {
    
}

//insert uring recursive
void Tree::insert(const Address& address) {
    insertRecursive(root, address);
}

//search using recursive
bool Tree::search(const Address& address) const {
    return searchRecursive(root, address);
}

//get details of address
Address Tree::retrieveDetails(const Address& address) const {
    return searchRecursiveDetails(root, address);
}

//used in insert
void Tree::insertRecursive(Node*& current, const Address& address) {
    if (current == nullptr) {
        current = new Node(address);
    } else {
        int comparison = address.compare(current->data);
        if (comparison == -1) {
            insertRecursive(current->left, address);
        } else if (comparison == 1) {
            insertRecursive(current->right, address);
        }
        //If comparison == 0, address is already in tree, no action is needed.
    }
}

//used in search
bool Tree::searchRecursive(Node* current, const Address& address) const {
    if (current == nullptr) {
        return false;
    }
    
    int comparison = address.compare(current->data);
    if (comparison == 0) {
        return true;
    } else if (comparison == -1) {
        return searchRecursive(current->left, address);
    } else {
        return searchRecursive(current->right, address);
    }
}

//retrieve address details
Address Tree::searchRecursiveDetails(Node* current, const Address& address) const {
    if (current == nullptr) {
        return Address(); //Return default Address if address is not found
    }
    
    int comparison = address.compare(current->data);
    if (comparison == 0) {
        return current->data;  //Return found address
    } else if (comparison == -1) {
        return searchRecursiveDetails(current->left, address);
    } else {
        return searchRecursiveDetails(current->right, address);
    }
}