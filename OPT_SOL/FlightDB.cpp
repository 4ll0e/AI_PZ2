#include "FlightDB.h"
#include <iostream>

void FlightDB::setup() {
    addFlight("New York", "Chicago", 1000);
    addFlight("Chicago", "Denver", 1000);
    addFlight("New York", "Toronto", 800);
    addFlight("New York", "Denver", 1900);
    addFlight("Toronto", "Calgary", 1500);
    addFlight("Toronto", "Los Angeles", 1800);
    addFlight("Toronto", "Chicago", 500);
    addFlight("Denver", "Urbana", 1000);
    addFlight("Denver", "Houston", 1500);
    addFlight("Houston", "Los Angeles", 1500);
    addFlight("Denver", "Los Angeles", 1000);
}

void FlightDB::resetSkipFlags() {
    for (auto& flight : flights) {
        flight.skip = false;
    }
}


void FlightDB::addFlight(const std::string& from, const std::string& to, int distance) {
    flights.push_back({ from, to, distance, false });
}

bool FlightDB::isFlight(const std::string& from, const std::string& to, BacktrackStack& btStack) {
    std::string anywhere;
    int dist = match(from, to);
    if (dist > 0) {
        btStack.push(from, to, dist);
        return true;
    }

    dist = find(from, anywhere);
    if (dist > 0) {
        btStack.push(from, anywhere, dist);
        return isFlight(anywhere, to, btStack);
    }

    if (!btStack.empty()) {
        std::string prevFrom, prevTo;
        int prevDist;
        btStack.pop(prevFrom, prevTo, prevDist);
        return isFlight(prevFrom, to, btStack);
    }

    return false;
}

int FlightDB::calculateRoute(const std::string& to, BacktrackStack& btStack, SolutionStack& solutionStack) {
    int totalDist = 0;
    for (const auto& step : btStack.getStack()) {
        std::cout << step.from << " to ";
        totalDist += step.dist;
    }
    std::cout << to << "\nDistance is " << totalDist << '\n';

    if (solutionStack.isOptimal(totalDist)) {
        solutionStack.clear();
        for (const auto& step : btStack.getStack()) {
            solutionStack.push(step.from, step.to, step.dist);
        }
    }
    return totalDist;
}

int FlightDB::match(const std::string& from, const std::string& to) {
    for (const auto& flight : flights) {
        if (flight.from == from && flight.to == to) return flight.distance;
    }
    return 0;
}

int FlightDB::find(const std::string& from, std::string& anywhere) {
    for (auto& flight : flights) {
        if (flight.from == from && !flight.skip) {
            flight.skip = true;
            anywhere = flight.to;
            return flight.distance;
        }
    }
    return 0;
}
