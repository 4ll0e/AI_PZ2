#include <iostream>
#include <string>
#include "Flight.h"
#include "Route.h"

void setup(FlightManager& flightManager) {
    flightManager.addFlight("London", "Paris", 450);
    flightManager.addFlight("Paris", "Berlin", 1050);
    flightManager.addFlight("London", "Amsterdam", 350);
    flightManager.addFlight("Amsterdam", "Berlin", 650);
    flightManager.addFlight("Berlin", "Warsaw", 600);
    flightManager.addFlight("Warsaw", "Moscow", 1250);
    flightManager.addFlight("Berlin", "Prague", 350);
    flightManager.addFlight("Prague", "Vienna", 300);
    flightManager.addFlight("Vienna", "Rome", 800);
    flightManager.addFlight("Rome", "Madrid", 1950);
    flightManager.addFlight("Madrid", "Lisbon", 600);
}

int main() {
    FlightManager flightManager;
    setup(flightManager);

    RouteManager routeManager;

    std::string from, to;
    std::cout << "From? ";
    std::getline(std::cin, from);
    std::cout << "To? ";
    std::getline(std::cin, to);

    if (routeManager.isFlight(from, to, flightManager)) {
        routeManager.printRoute(to);
    }
    else {
        std::cout << "No route found from " << from << " to " << to << std::endl;
    }

    return 0;
}
