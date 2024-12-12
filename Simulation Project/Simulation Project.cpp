#include "Simulation.h"
#include <iostream>

int main() {
    int simulationTime, numServers, transactionTime, arrivalTime;

    std::cout << "Enter the number of time units for the simulation: ";
    std::cin >> simulationTime;
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the server transaction time units: ";
    std::cin >> transactionTime;
    std::cout << "Enter time units between customer arrivals: ";
    std::cin >> arrivalTime;

    runSimulation(simulationTime, numServers, transactionTime, arrivalTime);

    return 0;
}
