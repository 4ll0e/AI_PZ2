#ifndef FLIGHT_DB_H
#define FLIGHT_DB_H

#include <vector>
#include <string>
#include "stack.h"

struct Flight {
    std::string from;
    std::string to;
    int distance;
    bool skip = false;
};

class FlightDB {
public:
    void setup();
    bool isFlight(const std::string& from, const std::string& to, BacktrackStack& btStack);
    int calculateRoute(const std::string& to, BacktrackStack& btStack, SolutionStack& solutionStack);
    void addFlight(const std::string& from, const std::string& to, int distance);
    void resetSkipFlags();

private:
    int find(const std::string& from, std::string& anywhere);
    int match(const std::string& from, const std::string& to);
    std::vector<Flight> flights;

};

#endif
