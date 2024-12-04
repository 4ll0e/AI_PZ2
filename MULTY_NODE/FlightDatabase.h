#ifndef FLIGHTDATABASE_H
#define FLIGHTDATABASE_H

#include "Flight.h"
#include <vector>

class FlightDatabase {
private:
    std::vector<Flight> flights;

public:
    void addFlight(const std::string& from, const std::string& to, int dist);
    int match(const std::string& from, const std::string& to) const;
    void retract(const std::string& from, const std::string& to);
    void clearmarkers();
    int findClosest(const std::string& from, std::string& anywhere);
    int getDistance(const std::string& from, const std::string& to) const;
};

#endif // FLIGHTDATABASE_H
