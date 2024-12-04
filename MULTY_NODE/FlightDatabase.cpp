#include "FlightDatabase.h"
#include <algorithm>
#include <iostream>

void FlightDatabase::addFlight(const std::string& from, const std::string& to, int dist) {
    if (flights.size() < 100) {
        flights.push_back({ from, to, dist, false });
    }
    else {
        std::cout << "Flight database is full.\n";
    }
}

int FlightDatabase::match(const std::string& from, const std::string& to) const {
    for (const auto& flight : flights) {
        if (flight.from == from && flight.to == to) {
            return flight.distance;
        }
    }
    return 0;
}

void FlightDatabase::retract(const std::string& from, const std::string& to) {
    for (auto& flight : flights) {
        if (flight.from == from && flight.to == to) {
            flight.from.clear();
            return;
        }
    }
}

void FlightDatabase::clearmarkers() {
    for (auto& flight : flights) {
        flight.skip = false;
    }
}

int FlightDatabase::findClosest(const std::string& from, std::string& anywhere) {
    int dist = 32000;  // A large number
    for (auto& flight : flights) {
        if (flight.from == from && !flight.skip) {
            if (flight.distance < dist) {
                anywhere = flight.to;
                dist = flight.distance;
                flight.skip = true;
            }
        }
    }
    return dist == 32000 ? 0 : dist;
}

int FlightDatabase::getDistance(const std::string& from, const std::string& to) const {
    for (const auto& flight : flights) {
        if (flight.from == from && flight.to == to) {
            return flight.distance;
        }
    }
    return 0;
}
