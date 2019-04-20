/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Queue.hp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Header of Queue
 */

#ifndef HW06_QUEUE_H
#define HW06_QUEUE_H

#include "Node.h"

template <class ItemType>
    class Queue {
    private:
        int startPos;
        int endPos;
        Event<ItemType>* queueData;

    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        bool enqueue(const Event<ItemType>& newData);
        bool dequeue();
        Event<ItemType> peekFront() const;

    };

#endif //HW06_QUEUE_H
