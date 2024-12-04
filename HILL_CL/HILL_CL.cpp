#include "FlightDatabase.h"
#include <iostream>

int main() {
    FlightDatabase db;
    db.setupDatabase();

    std::string from, to;
    std::cout << "From: ";
    std::getline(std::cin, from);
    std::cout << "To: ";
    std::getline(std::cin, to);

    db.findRoute(from, to);
    db.printRoute(to);

    return 0;
}
