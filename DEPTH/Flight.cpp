#include "Flight.h"

Flight::Flight(const std::string& f, const std::string& t, int d)
    : from(f), to(t), distance(d), skip(false) {}

void FlightManager::addFlight(const std::string& from, const std::string& to, int distance) {
    flights.emplace_back(from, to, distance);
}

int FlightManager::match(const std::string& from, const std::string& to) {
    for (auto& flight : flights) {
        if (flight.from == from && flight.to == to && !flight.skip) {
            flight.skip = true;
            return flight.distance;
        }
    }
    return 0;
}

int FlightManager::find(const std::string& from, std::string& anywhere) {
    for (auto& flight : flights) {
        if (flight.from == from && !flight.skip) {
            flight.skip = true;
            anywhere = flight.to;
            return flight.distance;
        }
    }
    return 0;
}

const std::vector<Flight>& FlightManager::getFlights() const {
    return flights;
}
