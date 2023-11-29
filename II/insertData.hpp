#ifndef INSERTDATA_HPP
#define INSERTDATA_HPP

#include <iostream>
#include "priorityQueue.hpp"

void insertData(minPriorityQueue *&queue)
{
    // Insert the data into the queue
    insert(queue, (new Node("\u0627", 0.07)));
    insert(queue, (new Node("\u0628", 0.81)));
    insert(queue, (new Node("\u062A", 0.53)));
    insert(queue, (new Node("\u062B", 0.24)));
    insert(queue, (new Node("\u062C", 0.86)));
    insert(queue, (new Node("\u062D", 0.28)));
    insert(queue, (new Node("\u062E", 0.72)));
    insert(queue, (new Node("\u062F", 0.70)));
    insert(queue, (new Node("\u0630", 0.16)));
    insert(queue, (new Node("\u0631", 0.58)));
    insert(queue, (new Node("\u0632", 0.80)));
    insert(queue, (new Node("\u0633", 0.33)));
    insert(queue, (new Node("\u0634", 0.94)));
    insert(queue, (new Node("\u0635", 0.33)));
    insert(queue, (new Node("\u0636", 0.09)));
    insert(queue, (new Node("\u0637", 0.10)));
    insert(queue, (new Node("\u0638", 0.21)));
    insert(queue, (new Node("\u0639", 0.21)));
    insert(queue, (new Node("\u063A", 0.19)));
    insert(queue, (new Node("\u0641", 0.54)));
    insert(queue, (new Node("\u0642", 0.50)));
    insert(queue, (new Node("\u0643", 0.45)));
    insert(queue, (new Node("\u0644", 0.22)));
    insert(queue, (new Node("\u0646", 0.29)));
    insert(queue, (new Node("\u0647", 0.85)));
    insert(queue, (new Node("\u0648", 0.57)));
    insert(queue, (new Node("\u064A", 0.49)));
    insert(queue, (new Node("\u0626", 0.98)));
}

#endif