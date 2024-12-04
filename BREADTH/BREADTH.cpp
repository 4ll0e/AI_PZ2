#include <iostream>
#include "FlightMap.h"

int main() {
    FlightMap fm;
    fm.addFlight("London", "Paris", 450);
    fm.addFlight("Paris", "Berlin", 1050);
    fm.addFlight("London", "Amsterdam", 350);
    fm.addFlight("Amsterdam", "Berlin", 650);
    fm.addFlight("Berlin", "Warsaw", 600);
    fm.addFlight("Warsaw", "Moscow", 1250);
    fm.addFlight("Berlin", "Prague", 350);
    fm.addFlight("Prague", "Vienna", 300);
    fm.addFlight("Vienna", "Rome", 800);
    fm.addFlight("Rome", "Madrid", 1950);
    fm.addFlight("Madrid", "Lisbon", 600);

    std::string start, destination;
    std::cout << "Enter starting city: ";
    std::cin >> start;
    std::cout << "Enter destination city: ";
    std::cin >> destination;

    fm.findRoute(start, destination);

    return 0;
}
