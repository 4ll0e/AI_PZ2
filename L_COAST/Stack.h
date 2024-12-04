#ifndef STACK_H
#define STACK_H

#include <string>
#include "Flight.h"

class Stack {
private:
    static const int MAX = 100;
    Flight* stack[MAX];
    int tos;

public:
    Stack() : tos(0) {}

    bool push(Flight* flight) {
        if (tos < MAX) {
            stack[tos++] = flight;
            return true;
        }
        return false; // Stack overflow
    }

    Flight* pop() {
        if (tos > 0) {
            return stack[--tos];
        }
        return nullptr; // Stack underflow
    }

    bool isEmpty() const {
        return tos == 0;
    }
};

#endif
