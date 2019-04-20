/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file PriorityQueue.cpp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Implementation of Priority Queue
 */

#include "PriorityQueue.h"

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue() : head(nullptr) {}

template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
    Node<ItemType>* last;
    Node<ItemType>* current = head;

    while(current != nullptr) {
        last = current;
        current = current -> nodeNext;
        delete last;
    }
    head = nullptr;

}
template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
   if(head == nullptr) {
       return true;
   }
    return false;
}

template <class ItemType>
bool PriorityQueue<ItemType>::enqueue(const Event<ItemType>& newData) {
    if(&newData == nullptr) {
        return false;
    }

    if(head == nullptr || newData.getArrivalTime()  < head -> nodeData.getArrivalTime()) {
        Node<ItemType>* tNode = new Node<ItemType>(newData, head);
        head = tNode;
        return true;
    }

    Node<ItemType>* current = head;
    Node<ItemType>* previous = head;

    while(current != nullptr && (newData.getArrivalTime() >
                                                current -> nodeData.getArrivalTime())) {

        previous = current;
        current = current -> nodeNext;
    }

    if (current != nullptr && (newData.getEventType() == 'D' &&
                                    current -> getData().getEventType() == 'A')) {

        if(newData.getArrivalTime() == current->nodeData.getArrivalTime()) {

            previous = current;
            current = current -> nodeNext;
        }
    }

    Node<ItemType>* tNode = new Node<ItemType>(newData, previous -> nodeNext);
    previous -> nodeNext(tNode);
    return true;
}

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue() {
    if(head == nullptr) {
        return false;
    }
    Node<ItemType>* headNext = head -> nodeNext;
    delete head;
    head = headNext;
    return true;
}

template <class ItemType>
Event<ItemType> PriorityQueue<ItemType>::peekFront() const {
    if(head == nullptr) {
        std::cout << "Priority Queue is empty" << std::endl;
        return Event<ItemType>();
    }
    else {
        return head -> nodeData;
    }
}


