/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Node.h
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Template for Node
 */

#ifndef HW06_NODE_H
#define HW06_NODE_H

#include "Event.h"

template <class ItemType>
    class Node {

    public:
        Event<ItemType> nodeData;
        Node* nodeNext;
        Node();
        Node(Event<ItemType> theData);

        Node(Event<ItemType> theData, Node* theNextNode);
        ~Node();
    };

#endif //HW06_NODE_H
