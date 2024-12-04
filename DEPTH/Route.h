#ifndef ROUTE_H
#define ROUTE_H

#include <stack>
#include <string>
#include "Flight.h"

struct StackFrame {
    std::string from;
    std::string to;
    int distance;
};

class RouteManager {
public:
    bool isFlight(const std::string& from, const std::string& to, FlightManager& flightManager);
    void printRoute(const std::string& to);

private:
    std::stack<StackFrame> routeStack;
};

#endif // ROUTE_H
