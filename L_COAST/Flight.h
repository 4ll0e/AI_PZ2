#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    std::string from;
    std::string to;
    int distance;
    bool skip;

    Flight(const std::string& from, const std::string& to, int distance)
        : from(from), to(to), distance(distance), skip(false) {}
};

#endif
