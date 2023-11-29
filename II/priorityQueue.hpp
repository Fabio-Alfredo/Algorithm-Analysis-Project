#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// This struct is used to represent the nodes of the priority queue
struct Node
{
    string symbol;
    double probability;
    Node *left;
    Node *right;
    Node *parent;

    // Constructor
    Node(const string &symbol, double probability)
    {
        this->symbol = symbol;
        this->probability = probability;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// This struct is used to represent the priority queue
struct minPriorityQueue
{
    Node *node;
    minPriorityQueue *leftNode;
    minPriorityQueue *rightNode;
    minPriorityQueue(Node *node)
    {
        this->node = node;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
    }
};

void min_heapify(minPriorityQueue *&root)
{
    // If the root is null, return
    if (!root)
    {
        return;
    }
    //Find the minimum between the root and its children
    minPriorityQueue *minimum = root;
    // If the left child is smaller than the root, set the left child as the minimum
    if (root->leftNode && root->leftNode->node->probability < minimum->node->probability)
    {
        minimum = root->leftNode;
    }
    //If the right child is smaller than the root, set the right child as the minimum
    if (root->rightNode && root->rightNode->node->probability < minimum->node->probability)
    {
        minimum = root->rightNode;
    }
    // If the minimum is not the root, swap the root with the minimum
    if (minimum != root)
    {
        swap(root->node, minimum->node);
        min_heapify(minimum);
    }
}

void insert(minPriorityQueue *&root, Node *newNode)
{
    // If the root is null, set the new node as the root
    if (root == nullptr)
    {
        root = new minPriorityQueue(newNode);
    }
    else
    {
        // If the left child is null, set the new node as the left child
        if (!root->leftNode)
        {
            root->leftNode = new minPriorityQueue(newNode);
        }
        // If the right child is null, set the new node as the right child
        else if (!root->rightNode)
        {
            root->rightNode = new minPriorityQueue(newNode);
        }
        else
        {
            // If the left child has a smaller probability than the right child, insert the new node in the left child
            if (root->leftNode->node->probability < root->rightNode->node->probability)
            {
                insert(root->leftNode, newNode);
            }
            // If the right child has a smaller probability than the left child, insert the new node in the right child
            else
            {
                insert(root->rightNode, newNode);
            }
        }
    }
    // Reorder the priority queue
    min_heapify(root);
}

Node *extractMinimum(minPriorityQueue *&root)
{
    // If the root is null, return null
    if (!root)
    {
        return nullptr;
    }
    // Extract the minimum node
    Node *minimumNode = root->node;
    if (root->leftNode && root->rightNode)
    {
        // If the left child has a smaller probability than the right child, set the left child of the root as the root
        if (root->leftNode->node->probability < root->rightNode->node->probability)
        {
            root->node = root->leftNode->node;
            extractMinimum(root->leftNode);
        }
        // If the right child has a smaller probability than the left child, set the right child of the root as the root
        else
        {
            root->node = root->rightNode->node;
            extractMinimum(root->rightNode);
        }
    }
    // If the root has no children, set the root as null
    else
    {
        minPriorityQueue *aux = root;
        // If the root has a left child, set the left child as the root
        if (root->leftNode)
        {
            root = root->leftNode;
        }
        // If the root has a right child, set the right child as the root
        else
        {
            root = root->rightNode;
        }
        // Delete the old root
        delete aux;
    }
    return minimumNode;
}

void showPreOrder(minPriorityQueue *node)
{
    // If the node is not null, print the symbol and the probability of the node
    if (node)
    {
        cout << "Simbolo: " << node->node->symbol << ", probability: " << node->node->probability << endl;
        // Recursively call the function for the left and right children nodes  
        showPreOrder(node->leftNode);
        showPreOrder(node->rightNode);
    }
}

void showData(minPriorityQueue *root)
{
    // If the root is null, print that the minimum priority queue is empty
    if (!root)
    {
        cout << "La cola de prioridad mínima está vacía." << endl;
        return;
    }
    // Print the minimum priority queue
    showPreOrder(root);
}

void showMinimumQueue(minPriorityQueue *&root)
{
    cout << "Mostrando cola de prioridad mínima ordenada de menor a mayor probabilidad:" << endl;
    // While the root is not null, extract the minimum node and print it
    while (root)
    {
        // Extract the minimum node
        Node *minimum = extractMinimum(root);
        // Print the symbol and the probability of the minimum node
        cout << "Simbolo: " << minimum->symbol << ", probabilidad: " << minimum->probability << endl;
        // Delete the minimum node to free memory   
        delete minimum; // Liberar memoria del node extraído
    }
    // when the minimum priority queue is empty print this message
    cout << "Fin de la cola de prioridad mínima." << endl;
}
#endif
