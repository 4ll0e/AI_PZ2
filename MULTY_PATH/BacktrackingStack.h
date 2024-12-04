#ifndef BACKTRACKINGSTACK_H
#define BACKTRACKINGSTACK_H

#include "Flight.h"
#include <vector>
#include <string>

class BacktrackingStack {
public:
    struct StackEntry {
        std::string from;
        std::string to;
        int dist;
    };

private:
    std::vector<StackEntry> stack;

public:
    void push(const std::string& from, const std::string& to, int dist);
    void pop(std::string& from, std::string& to, int& dist);
    bool isEmpty() const;
    void clear();
    const std::vector<StackEntry>& getStack() const;
};

#endif
