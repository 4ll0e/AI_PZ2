#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

struct Flight {
    std::string from;
    std::string to;
    int distance;
    bool skip;  // Используется для обратного поиска
};

#endif // FLIGHT_H
