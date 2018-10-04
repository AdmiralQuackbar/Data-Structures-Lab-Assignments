#include "BTree.h" 
#include <iostream>

BTree::BTree() :root(NULL){}

BTree::~BTree() {
    destroy_tree();
}

void BTree::insert(int key) {
    insert(key, root);
}

Node* BTree::search(int key) {
    return search(key, root);
}

void BTree::destroy_tree() {
    destroy_tree(root);
}

Node* BTree::BTree_root() {
    return root;
}

void BTree::destroy_tree(Node *leaf)
{
    if(leaf == NULL) {}
    else {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key, Node *&leaf)
{
    if(leaf == NULL) {
        Node* temp = new Node;
        temp->right = NULL;
        temp->left = NULL;
        temp->key_value = key;
        leaf = temp;
    }
    else if(key < leaf->key_value) {
        insert(key, leaf->left);
    }
    else {
        insert(key, leaf->right);
    }
}

Node* BTree::search(int key, Node *leaf)
{
    if(leaf == NULL) {
        return NULL;
    }
    else if(key == leaf->key_value) {
        return leaf;
    }
    else if(key < leaf->key_value) {
        return search(key, leaf->left);
    }
    else {
        return search(key, leaf->right);
    }
}

