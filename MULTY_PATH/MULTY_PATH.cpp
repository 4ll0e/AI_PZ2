#include <iostream>
#include <conio.h>
#include <cstring>
#include "FlightSearch.h"

void setup(FlightSearch& fs);

int main() {
    FlightSearch fs;
    setup(fs);

    std::string from, to;
    std::cout << "from? ";
    std::cin >> from;
    std::cout << "to? ";
    std::cin >> to;

    do {
        int dist = fs.findRoute(from, to);
        if (!dist) break;
        fs.clearStack(); // Reset the backtracking stack
    } while (_kbhit() && _getch() != 'q');

    return 0;
}

void setup(FlightSearch& fs) {
    fs.assertFlight("New York", "Chicago", 1000);
    fs.assertFlight("Chicago", "Denver", 1000);
    fs.assertFlight("New York", "Toronto", 800);
    fs.assertFlight("New York", "Denver", 1900);
    fs.assertFlight("Toronto", "Calgary", 1500);
    fs.assertFlight("Toronto", "Los Angeles", 1800);
    fs.assertFlight("Toronto", "Chicago", 500);
    fs.assertFlight("Denver", "Urbana", 1000);
    fs.assertFlight("Denver", "Houston", 1500);
    fs.assertFlight("Houston", "Los Angeles", 1500);
    fs.assertFlight("Denver", "Los Angeles", 1000);
}
