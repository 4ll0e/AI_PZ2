#include "stack.h"

void BacktrackStack::push(const std::string& from, const std::string& to, int dist) {
    stack.push_back({ from, to, dist });
}

void BacktrackStack::pop(std::string& from, std::string& to, int& dist) {
    if (!stack.empty()) {
        auto step = stack.back();
        stack.pop_back();
        from = step.from;
        to = step.to;
        dist = step.dist;
    }
}

bool BacktrackStack::empty() const {
    return stack.empty();
}

const std::vector<Step>& BacktrackStack::getStack() const {
    return stack;
}

void BacktrackStack::clear() {
    stack.clear();
}

void SolutionStack::push(const std::string& from, const std::string& to, int dist) {
    solution.push_back({ from, to, dist });
}

void SolutionStack::clear() {
    solution.clear();
    optimalDistance = INT_MAX;
}

bool SolutionStack::isOptimal(int distance) {
    if (distance < optimalDistance) {
        optimalDistance = distance;
        return true;
    }
    return false;
}

void SolutionStack::printOptimalSolution(const std::string& to) const {
    int totalDist = 0;
    for (const auto& step : solution) {
        std::cout << step.from << " to ";
        totalDist += step.dist;
    }
    std::cout << to << "\nDistance is " << totalDist << '\n';
}
