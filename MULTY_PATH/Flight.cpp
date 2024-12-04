#include "Flight.h"

Flight::Flight(const std::string& from, const std::string& to, int distance)
    : from(from), to(to), distance(distance), skip(false) {}
