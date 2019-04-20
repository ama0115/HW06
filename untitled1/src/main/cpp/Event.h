/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Event.h
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief Template of Event
 */

#ifndef HW06_EVENT_H
#define HW06_EVENT_H

#include <iostream>

template <class ItemType>
    class Event {
    private:
        char eventType;
        int arrivalTime;
        int timeLength;

    public:
        Event();
        Event(int arrTime, int theTimeLength);
        Event(int arrTime, int theTimeLength, char theEventType);
        ~Event();

        int getArrivalTime() const;
        int getTime() const;
        char getEventType() const;
        int setArrivalTime(int arrTime);
        int setEventType(char theEventType);
        int setTimeLength(int theTimeLength);
};


#endif //HW06_EVENT_H
