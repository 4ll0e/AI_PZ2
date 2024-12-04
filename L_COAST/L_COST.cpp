#include <iostream>
#include <string>
#include "Flight.h"
#include "Stack.h"
#include "Search.h"

// Глобальные переменные
std::vector<Flight> flightDatabase;
Stack bt_stack;

void assert_flight(const std::string& from, const std::string& to, int dist) {
    flightDatabase.push_back(Flight(from, to, dist));
}

void route(const std::string& to) {
    int dist = 0;
    Stack tempStack = bt_stack;
    while (!tempStack.isEmpty()) {
        Flight* f = tempStack.pop();
        std::cout << f->from << " to ";
        dist += f->distance;
    }
    std::cout << to << "\n";
    std::cout << "distance is " << dist << "\n";
}

int match(const std::string& from, const std::string& to) {
    for (auto& flight : flightDatabase) {
        if (flight.from == from && flight.to == to) {
            return flight.distance;
        }
    }
    return 0; // not found
}

int find(const std::string& from, std::string& anywhere) {
    int pos = 0;
    int dist = 32000; // Start with a large number
    for (auto& flight : flightDatabase) {
        if (flight.from == from && !flight.skip) {
            if (flight.distance < dist) {
                anywhere = flight.to;
                dist = flight.distance;
                pos = &flight - &flightDatabase[0]; // Store position
            }
        }
    }
    if (pos) {
        flightDatabase[pos].skip = true; // mark as used
        return flightDatabase[pos].distance;
    }
    return 0;
}

void isflight(const std::string& from, const std::string& to) {
    int dist = match(from, to);
    if (dist) {
        bt_stack.push(new Flight(from, to, dist));
        return;
    }

    std::string anywhere;
    dist = find(from, anywhere);
    if (dist) {
        bt_stack.push(new Flight(from, anywhere, dist));
        isflight(anywhere, to);
    }
    else if (!bt_stack.isEmpty()) {
        Flight* f = bt_stack.pop();
        isflight(f->from, f->to);
    }
}

void setup() {
    assert_flight("New York", "Chicago", 1000);
    assert_flight("Chicago", "Denver", 1000);
    assert_flight("New York", "Toronto", 800);
    assert_flight("New York", "Denver", 1900);
    assert_flight("Toronto", "Calgary", 1500);
    assert_flight("Toronto", "Los Angeles", 1800);
    assert_flight("Toronto", "Chicago", 500);
    assert_flight("Denver", "Urbana", 1000);
    assert_flight("Denver", "Houston", 1500);
    assert_flight("Houston", "Los Angeles", 1500);
    assert_flight("Denver", "Los Angeles", 1000);
}

int main() {
    std::string from, to;

    setup();
    std::cout << "from? ";
    std::getline(std::cin, from);
    std::cout << "to? ";
    std::getline(std::cin, to);
    isflight(from, to);
    route(to);

    return 0;
}
