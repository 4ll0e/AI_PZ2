#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <iostream>

struct Step {
    std::string from;
    std::string to;
    int dist;
};

class BacktrackStack {
public:
    void push(const std::string& from, const std::string& to, int dist);
    void pop(std::string& from, std::string& to, int& dist);
    bool empty() const;
    const std::vector<Step>& getStack() const;
    void clear();

private:
    std::vector<Step> stack;
};

class SolutionStack {
public:
    void push(const std::string& from, const std::string& to, int dist);
    void clear();
    bool isOptimal(int distance);
    void printOptimalSolution(const std::string& to) const;

private:
    std::vector<Step> solution;
    int optimalDistance = INT_MAX;
};

#endif
