#ifndef FLIGHTSEARCH_H
#define FLIGHTSEARCH_H

#include "Flight.h"
#include "BacktrackingStack.h"
#include <vector>
#include <string>

class FlightSearch {
public:
    FlightSearch();
    int findRoute(const std::string& from, const std::string& to);
    void assertFlight(const std::string& from, const std::string& to, int distance);
    void isFlight(const std::string& from, const std::string& to);
    int match(const std::string& from, const std::string& to);
    int find(const std::string& from, std::string& anywhere);
    void clearStack(); // Новый метод

private:
    std::vector<Flight> flightDB;
    BacktrackingStack btStack;
    int findPos;
};

#endif
