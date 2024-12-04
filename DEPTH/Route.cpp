#include "Route.h"
#include <iostream>

bool RouteManager::isFlight(const std::string& from, const std::string& to, FlightManager& flightManager) {
    int distance = flightManager.match(from, to);
    if (distance > 0) {
        routeStack.push({ from, to, distance });
        return true;
    }

    std::string anywhere;
    distance = flightManager.find(from, anywhere);
    if (distance > 0) {
        routeStack.push({ from, anywhere, distance });
        if (isFlight(anywhere, to, flightManager)) {
            return true;
        }
        routeStack.pop();
    }
    return false;
}

void RouteManager::printRoute(const std::string& to) {
    int totalDistance = 0;
    std::stack<StackFrame> reverseStack;

    while (!routeStack.empty()) {
        reverseStack.push(routeStack.top());
        routeStack.pop();
    }

    while (!reverseStack.empty()) {
        auto frame = reverseStack.top();
        reverseStack.pop();
        std::cout << frame.from << " to ";
        totalDistance += frame.distance;
    }

    std::cout << to << std::endl;
    std::cout << "Total distance: " << totalDistance << " miles" << std::endl;
}
