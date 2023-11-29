#include <iostream>
#include "priorityQueue.hpp"
#include "Huffman.hpp"
#include "insertData.hpp"

using namespace std;

int main()
{
    minPriorityQueue *queue = nullptr;

    insertData(queue);

    Node *root = huffmanTree(queue);
    cout << "Codigos Huffman:\n";
    huffmanCoding(root);

    return 0;
}

