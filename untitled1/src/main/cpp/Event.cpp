/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Event.cpp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Implementation of Event
 */

#include "Event.h"

template <class ItemType>
Event<ItemType>::Event(void) : eventType('A'), arrivalTime(0), timeLength(0) {}

template <class ItemType>
Event<ItemType>::Event(int arrTime, int theTimeLength) {
    eventType = 'A';
    arrivalTime = arrTime;
    timeLength = theTimeLength;
}

template <class ItemType>
Event<ItemType>::Event(int arrTime, int theTimeLength, char theEventType) {
    eventType = theEventType;
    arrivalTime = arrTime;
    timeLength = theTimeLength;

}
template <class ItemType>
Event<ItemType>::~Event() {}

template <class ItemType>
char Event<ItemType>::getEventType() const {
    return eventType;
}

template <class ItemType>
int Event<ItemType>::getArrivalTime() const {
    return arrivalTime;
}

template <class ItemType>
int Event<ItemType>::getTime() const {
    return timeLength;
}

template <class ItemType>
int Event<ItemType>::setEventType(char theEventType) {
    if(theEventType != 'A' && theEventType != 'D') {
        return 1;
    }
    eventType = theEventType;
    return  0;
}

template <class ItemType>
int Event<ItemType>::setArrivalTime(int arrTime) {
    if(arrTime < 0) {
        return  1;
    }
    arrivalTime = arrTime;
    return 0;
}

template <class ItemType>
int Event<ItemType>::setTimeLength(int theTimeLength) {
    if(theTimeLength < 0) {
        return 1;
    }
    timeLength = theTimeLength;
    return 0;
}