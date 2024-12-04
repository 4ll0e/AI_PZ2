#include "FlightDatabase.h"
#include <iostream>
#include <algorithm>

void FlightDatabase::addFlight(const std::string& from, const std::string& to, int distance) {
    flights.push_back({ from, to, distance, false });
}

int FlightDatabase::findFarthest(const std::string& from, std::string& anywhere) {
    int maxDistance = 0;
    size_t position = 0;
    for (size_t i = 0; i < flights.size(); ++i) {
        if (flights[i].from == from && !flights[i].skip) {
            if (flights[i].distance > maxDistance) {
                maxDistance = flights[i].distance;
                position = i;
            }
        }
    }
    if (maxDistance > 0) {
        flights[position].skip = true;
        anywhere = flights[position].to;
    }
    return maxDistance;
}

int FlightDatabase::match(const std::string& from, const std::string& to) {
    for (const auto& flight : flights) {
        if (flight.from == from && flight.to == to) {
            return flight.distance;
        }
    }
    return 0; // Not found
}

void FlightDatabase::pushToStack(const std::string& from, const std::string& to, int distance) {
    backtrackStack.push({ from, to, distance });
}

bool FlightDatabase::popFromStack(std::string& from, std::string& to, int& distance) {
    if (!backtrackStack.empty()) {
        auto item = backtrackStack.top();
        backtrackStack.pop();
        from = item.from;
        to = item.to;
        distance = item.distance;
        return true;
    }
    return false;
}

void FlightDatabase::printRoute(const std::string& to) {
    int totalDistance = 0;
    std::stack<StackItem> reverseStack;
    while (!backtrackStack.empty()) {
        reverseStack.push(backtrackStack.top());
        backtrackStack.pop();
    }
    while (!reverseStack.empty()) {
        auto item = reverseStack.top();
        reverseStack.pop();
        std::cout << item.from << " to ";
        totalDistance += item.distance;
    }
    std::cout << to << std::endl;
    std::cout << "Total distance: " << totalDistance << " km" << std::endl;
}

void FlightDatabase::setupDatabase() {
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

void FlightDatabase::findRoute(const std::string& from, const std::string& to) {
    std::string anywhere;
    int distance = match(from, to);
    if (distance > 0) {
        pushToStack(from, to, distance);
        return;
    }
    while ((distance = findFarthest(from, anywhere)) > 0) {
        pushToStack(from, anywhere, distance);
        findRoute(anywhere, to);
        return;
    }
    if (!backtrackStack.empty()) {
        popFromStack(anywhere, anywhere, distance);
        findRoute(anywhere, to);
    }
}
