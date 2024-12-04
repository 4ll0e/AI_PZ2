#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

struct Flight {
    std::string from;
    std::string to;
    int distance;
    bool skip;

    Flight(const std::string& f, const std::string& t, int d);
};

class FlightManager {
public:
    void addFlight(const std::string& from, const std::string& to, int distance);
    int match(const std::string& from, const std::string& to);
    int find(const std::string& from, std::string& anywhere);
    const std::vector<Flight>& getFlights() const;

private:
    std::vector<Flight> flights;
};

#endif // FLIGHT_H
