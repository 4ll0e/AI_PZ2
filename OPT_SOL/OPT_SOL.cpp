#include <iostream>
#include <string>
#include "FlightDB.h"
#include "stack.h"

int main() {
    bool quit = true;
    FlightDB flightDB;
    flightDB.setup();

    std::string from, to;
    std::cout << "From? ";
    std::getline(std::cin, from);
    std::cout << "To? ";
    std::getline(std::cin, to);

    BacktrackStack btStack;
    SolutionStack solutionStack;

do {
    if (flightDB.isFlight(from, to, btStack)) {
        int distance = flightDB.calculateRoute(to, btStack, solutionStack);
        btStack.clear();
        flightDB.resetSkipFlags(); // Сбрасываем флаги
        quit = false;
        if (distance == 0) break;
    } else {
        std::cout << "No route found.\n";
        quit = false;
        break;
    }
} while (quit);


    solutionStack.printOptimalSolution(to);
    return 0;
}
