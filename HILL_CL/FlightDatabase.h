#ifndef FLIGHTDATABASE_H
#define FLIGHTDATABASE_H

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

struct Flight {
    std::string from;
    std::string to;
    int distance;
    bool skip = false; // Used in backtracking
};

struct StackItem {
    std::string from;
    std::string to;
    int distance;
};

class FlightDatabase {
private:
    std::vector<Flight> flights;
    std::stack<StackItem> backtrackStack;

public:
    void addFlight(const std::string& from, const std::string& to, int distance);
    int findFarthest(const std::string& from, std::string& anywhere);
    int match(const std::string& from, const std::string& to);
    void pushToStack(const std::string& from, const std::string& to, int distance);
    bool popFromStack(std::string& from, std::string& to, int& distance);
    void printRoute(const std::string& to);
    void setupDatabase();
    void findRoute(const std::string& from, const std::string& to);
};

#endif // FLIGHTDATABASE_H
