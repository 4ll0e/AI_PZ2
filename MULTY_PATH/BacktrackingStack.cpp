#include "BacktrackingStack.h"
#include <iostream>

void BacktrackingStack::push(const std::string& from, const std::string& to, int dist) {
    stack.push_back({ from, to, dist });
}

void BacktrackingStack::pop(std::string& from, std::string& to, int& dist) {
    if (!stack.empty()) {
        auto& top = stack.back();
        from = top.from;
        to = top.to;
        dist = top.dist;
        stack.pop_back();
    }
    else {
        std::cout << "Stack underflow.\n";
    }
}

bool BacktrackingStack::isEmpty() const {
    return stack.empty();
}

void BacktrackingStack::clear() {
    stack.clear();
}

const std::vector<BacktrackingStack::StackEntry>& BacktrackingStack::getStack() const {
    return stack;
}
