/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file PriorityQueue.h
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Header of PriorityQueue
 */

#ifndef HW06_PRIORITYQUEUE_H
#define HW06_PRIORITYQUEUE_H

#include "Event.h"
#include "Node.h"

template <class ItemType>
    class PriorityQueue {
    private:
        Node<ItemType>* head;

    public:
        PriorityQueue();
        ~PriorityQueue();
        bool isEmpty() const;
        bool enqueue(const Event<ItemType>& newEvent);
        bool dequeue();
        Event<ItemType> peekFront() const;
    };


#endif //HW06_PRIORITYQUEUE_H
