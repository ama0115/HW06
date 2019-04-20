/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Queue.cpp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Implentation of Queue
 */

#include "Queue.h"

template <class ItemType>
Queue<ItemType>::Queue() : startPos(0), endPos(0), queueData(nullptr) {
   queueData = new Event<ItemType>[101];
}

template <class ItemType>
Queue<ItemType>::~Queue() {
    delete[] queueData;
    queueData = nullptr;
}



template <class ItemType>
bool Queue<ItemType>::isEmpty() const {
    if(startPos == endPos) {
        return true;
    }
    return false;
}

template <class ItemType>
bool Queue<ItemType>::enqueue(const Event<ItemType>& newData) {
    if((startPos % 101) == (endPos + 1)  & 101) {
        return false;
    }
    queueData[(endPos) & 101] = newData;
    endPos++;
    return true;
}

template <class ItemType>
bool Queue<ItemType>::dequeue() {
    if(startPos == endPos) {
        return false;
    }
    startPos++;
    return true;
}

template <class ItemType>
Event<ItemType> Queue<ItemType>::peekFront() const {
    return queueData[startPos % 101];
}



