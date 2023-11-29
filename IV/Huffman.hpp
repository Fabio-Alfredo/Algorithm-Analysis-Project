#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include "priorityQueue.hpp"

using namespace std;

Node* huffmanTree(minPriorityQueue*& root) {
    
    while (root && (root->leftNode || root->rightNode)) {
        // Extract the two minimum nodes
        Node* left = extractMinimum(root);
        Node* right = extractMinimum(root);
        // Create a new node with the sum of the probabilities of the two minimum nodes
        Node* node = new Node("", left->probability + right->probability);
        // Set the children nodes of the new node
        node->left = left;
        node->right = right;
        // Insert the new node in the queue
        insert(root, node);
    }
    if (root) {
        // Return the root of the Huffman tree
        return root->node;
    } else {
        // Return nullptr if the queue is empty
        return nullptr;
    }
}

// This function is used to generate the Huffman codes
void huffmanCoding(Node* root, string code = "") {
    
    // If the root is a leaf node, print the symbol and the code
    if (root && (!root->left && !root->right)) {
        cout << root->symbol << ": " << code << '\n';

    // If the root is not a leaf node, recursively call the function for the left and right children nodes
    } else if (root) {

        // If the recursively called function is called for the left child node, add a '0' to the code
        huffmanCoding(root->left, code + '0');
        // If the recursively called function is called for the right child node, add a '1' to the code
        huffmanCoding(root->right, code + '1');
    }
}

#endif
