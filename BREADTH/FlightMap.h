#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

class FlightMap {
public:
    void addFlight(const std::string& from, const std::string& to, int distance);
    void findRoute(const std::string& start, const std::string& destination);

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph;
    void printRoute(const std::string& start, const std::string& destination,
        const std::unordered_map<std::string, std::string>& prev, int totalDist);
};

#endif // FLIGHTMAP_H
