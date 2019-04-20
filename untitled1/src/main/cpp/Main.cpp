/**
 *CSC232 Data Structures
 *Missouri State University
 *
 **@file Main.cpp
 * @author Austin Alvidrez<ama0115@live.missouristate.edu>
 * @brief
 */

#include "Queue.h"
#include "PriorityQueue.h"
#include <fstream>
int inputToPriorityQueue(PriorityQueue<int> &inputPQ) {
    int tTime;
    int tLength;
    std::ifstream data{"input.dat"};
    if (!data) {
        std::cout << "error opening input.dat..." << std::endl;
        return EXIT_FAILURE;
    }

    while(data >> tTime >> tLength) {
        Event<int> tempEvent(tTime, tLength);
        inputPQ.enqueue(tempEvent);
    }
    data.close();
    return EXIT_SUCCESS;
}

int main(void) {
    Queue<int> bankQueue;

    PriorityQueue<int> eventListPQueue;

    bool tellerAvail = true;

    inputToPriorityQueue(eventListPQueue);

    int departureTimeTotal = 0;
    int processingTimeTotal = 0;
    int arrivalTimeTotal = 0;
    int eventCounter = 0;
    float waitTime;

    while(!eventListPQueue.isEmpty()) {
        Event<int> newEvent = eventListPQueue.peekFront();

        int presentTime = newEvent.getArrivalTime();

        if(newEvent.getEventType() == 'A') {
            eventListPQueue.dequeue();
            Event<int> bankCustomer = newEvent;

            if(bankQueue.isEmpty() && tellerAvail) {
                int departureTime = presentTime + bankCustomer.getTime();

                Event<char> newDepartureEvent('D', departureTime, 0);

                eventListPQueue.enqueue(newDepartureEvent);

                tellerAvail = false;
            }
            else {
                bankQueue.enqueue(bankCustomer);
            }
        std::cout << "Proccessing an arrival event at time: \t" <<
                 bankCustomer.getArrivalTime() << std::endl;
        eventCounter++;
        arrivalTimeTotal += bankCustomer.getArrivalTime();
        processingTimeTotal += bankCustomer.getTime();
        }
        else {
            eventListPQueue.dequeue();

            if(!bankQueue.isEmpty()) {
                Event<int> bankCustomer = bankQueue.peekFront();

                bankQueue.dequeue();

                int departureTime = presentTime + bankCustomer.getTime();

                Event<int> newDepartureEvent('D', departureTime, 0);

                eventListPQueue.enqueue(newDepartureEvent);
            }
            else{
                tellerAvail = true;
            }
            std::cout << "Processing a departure event at time: \t" <<
                presentTime << std::endl;
        }

    }
    waitTime = (float)(departureTimeTotal - processingTimeTotal - arrivalTimeTotal) /
            eventCounter;

    std::cout <<"Sim Ends" << std::endl << std::endl;
    std::cout << "fina stats: " << std::endl;
    std::cout <<"\tAvg amount of time spent waiting: " << waitTime << std::endl;

    return 0;
}

