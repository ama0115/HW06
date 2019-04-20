/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Node.cpp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Implementation of Node
 */

#include "Node.h"

template <class ItemType>
Node<ItemType>::Node() {
    nodeNext = nullptr;
}

template <class ItemType>
Node<ItemType>::Node(Event<ItemType> theData) {
    nodeData = theData;
    nodeNext = nullptr;
}

template <class ItemType>
Node<ItemType>::Node(Event<ItemType> theData, Node* theNextNode) {
    nodeData = theData;
    nodeNext = theNextNode;
}

template<class ItemType>
Node<ItemType>::~Node() {}
