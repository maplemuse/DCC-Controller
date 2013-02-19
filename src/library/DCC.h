#ifndef DCC_H
#define DCC_H

#include <Arduino.h>
#include <DCCCommand.h>

#define PRIORITY_QUEUE_SIZE 10
#define STANDARD_QUEUE_SIZE 10

class DCC {
    public:
        DCCCommand *priorityQueue;
        DCCCommand *standardQueue;
        byte writePos;

        DCC();
        DCC(int pin_a, int pin_b);
        ~DCC();

        void queueCommand(DCCCommand command);
    private:
        int _pinA;
        int _pinB;

        void _prepareQueues();
        void initializeTimer();
};

#endif