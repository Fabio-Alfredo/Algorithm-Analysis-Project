#include <iostream>
#include "priorityQueue.hpp"
#include "insertData.hpp"

using namespace std;

int main()
{
    minPriorityQueue *queue = nullptr;

    // Insert data into the queue
    insertData(queue);
    // showData(queue);
    showMinimumQueue(queue);

    return 0;
}

