#include <iostream>
#include "FlightDatabase.h"
#include "StackManager.h"

void setup(FlightDatabase& db);
void route(const StackManager& stackManager, const std::string& to);
void isflight(const std::string& from, const std::string& to, FlightDatabase& db, StackManager& stackManager);
int find(const std::string& from, std::string& anywhere, FlightDatabase& db);

int main() {
    FlightDatabase db;
    StackManager stackManager;

    setup(db);

    std::string from, to;
    std::cout << "From? ";
    std::getline(std::cin, from);
    std::cout << "To? ";
    std::getline(std::cin, to);

    isflight(from, to, db, stackManager);
    route(stackManager, to);

    return 0;
}

void setup(FlightDatabase& db) {
    db.addFlight("New York", "Chicago", 1000);
    db.addFlight("Chicago", "Denver", 1000);
    db.addFlight("New York", "Toronto", 800);
    db.addFlight("New York", "Denver", 1900);
    db.addFlight("Toronto", "Calgary", 1500);
    db.addFlight("Toronto", "Los Angeles", 1800);
    db.addFlight("Toronto", "Chicago", 500);
    db.addFlight("Denver", "Urbana", 1000);
    db.addFlight("Denver", "Houston", 1500);
    db.addFlight("Houston", "Los Angeles", 1500);
    db.addFlight("Denver", "Los Angeles", 1000);
}

void route(const StackManager& stackManager, const std::string& to) {
    int dist = 0;
    for (int i = 0; i < stackManager.getTos(); ++i) {
        std::cout << "Route " << i + 1 << "\n";
        dist += stackManager.getDistance();
    }
    std::cout << "Distance is " << dist << std::endl;
}

void isflight(const std::string& from, const std::string& to, FlightDatabase& db, StackManager& stackManager) {
    int dist = db.getDistance(from, to);
    if (dist) {
        stackManager.push(from, to, dist);
        return;
    }

    std::string anywhere;
    dist = find(from, anywhere, db);
    if (dist) {
        stackManager.push(from, anywhere, dist);
        isflight(anywhere, to, db, stackManager);
    }
    else if (stackManager.getTos() > 0) {
        std::string backFrom, backTo;
        int backDist;
        stackManager.pop(backFrom, backTo, backDist);
        isflight(backFrom, backTo, db, stackManager);
    }
}

int find(const std::string& from, std::string& anywhere, FlightDatabase& db) {
    return db.findClosest(from, anywhere);
}
