#include "FlightMap.h"
#include <iostream>
#include <queue>
#include <algorithm>

void FlightMap::addFlight(const std::string& from, const std::string& to, int distance) {
    graph[from].emplace_back(to, distance);
    graph[to].emplace_back(from, distance); // Если полеты двусторонние
}

void FlightMap::findRoute(const std::string& start, const std::string& destination) {
    std::unordered_set<std::string> visited;
    std::queue<std::pair<std::string, int>> q; // {текущий город, общая дистанция}
    std::unordered_map<std::string, std::string> prev; // для восстановления пути

    q.push({ start, 0 });
    visited.insert(start);

    while (!q.empty()) {
        auto current_pair = q.front();
        q.pop();

        std::string current = current_pair.first;
        int dist = current_pair.second;

        if (current == destination) {
            printRoute(start, destination, prev, dist);
            return;
        }

        for (const auto& pair : graph[current]) {
            std::string neighbor = pair.first;
            int weight = pair.second;

            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({ neighbor, dist + weight });
                prev[neighbor] = current;
            }
        }
    }

    std::cout << "No route found from " << start << " to " << destination << ".\n";
}


void FlightMap::printRoute(const std::string& start, const std::string& destination,
    const std::unordered_map<std::string, std::string>& prev, int totalDist) {
    std::vector<std::string> route;
    std::string current = destination;

    while (current != start) {
        route.push_back(current);
        current = prev.at(current);
    }
    route.push_back(start);

    std::reverse(route.begin(), route.end());
    std::cout << "Route found: ";
    for (const auto& city : route) {
        std::cout << city << " -> ";
    }
    std::cout << "END\nTotal Distance: " << totalDist << " km\n";
}
