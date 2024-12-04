#include "FlightSearch.h"
#include <iostream>
#include <cstring>

FlightSearch::FlightSearch() : findPos(0) {}

void FlightSearch::assertFlight(const std::string& from, const std::string& to, int distance) {
    flightDB.emplace_back(from, to, distance);
}

int FlightSearch::match(const std::string& from, const std::string& to) {
    for (int i = findPos - 1; i >= 0; i--) {
        if (flightDB[i].from == from && flightDB[i].to == to) {
            return flightDB[i].distance;
        }
    }
    return 0;
}

int FlightSearch::find(const std::string& from, std::string& anywhere) {
    for (; findPos < flightDB.size(); findPos++) {
        if (flightDB[findPos].from == from && !flightDB[findPos].skip) {
            anywhere = flightDB[findPos].to;
            flightDB[findPos].skip = true;
            return flightDB[findPos].distance;
        }
    }
    return 0;
}

void FlightSearch::isFlight(const std::string& from, const std::string& to) {
    int dist = match(from, to);
    if (dist) {
        btStack.push(from, to, dist);
        return;
    }

    std::string anywhere;
    dist = find(from, anywhere);
    if (dist) {
        btStack.push(from, to, dist);
        isFlight(anywhere, to);
    }
    else if (!btStack.isEmpty()) {
        std::string backFrom, backTo;
        int backDist;
        btStack.pop(backFrom, backTo, backDist);
        isFlight(backFrom, backTo);
    }
}

int FlightSearch::findRoute(const std::string& from, const std::string& to) {
    isFlight(from, to);
    int dist = 0;
    const auto& stack = btStack.getStack();
    for (const auto& entry : stack) {
        std::cout << entry.from << " to ";
        dist += entry.dist;
    }
    std::cout << to << "\nDistance is " << dist << std::endl;
    return dist;
}

void FlightSearch::clearStack() {
    btStack.clear(); 
}