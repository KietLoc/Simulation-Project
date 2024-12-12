#include "Simulation.h"
#include <iostream>

void runSimulation(int simulationTime, int numServers, int transactionTime, int arrivalTime) {
    ServerList serverList(numServers);
    CustomerQueue customerQueue(arrivalTime);

    int totalCustomersArrived = 0;

    for (int currentTime = 0; currentTime < simulationTime; currentTime++) {
        serverList.updateServers();
        customerQueue.updateWaitTimes();
        customerQueue.addCustomer(currentTime);
        totalCustomersArrived++;

        while (auto customer = customerQueue.removeCustomer()) {
            int freeServerIndex = serverList.findFreeServer();
            if (freeServerIndex != -1) {
                serverList.assignCustomerToFreeServer(customer, transactionTime);
            }
            else {
                break;
            }
        }
    }

    int totalWaitTime = serverList.getTotalWaitTime();
    int totalCustomersServed = serverList.getTotalCustomersServed();
    int remainingCustomers = customerQueue.getQueueSize();

    std::cout << "Simulation Results:\n";
    std::cout << "Number of customers left in queue: " << remainingCustomers << std::endl;
    std::cout << "Number of customers that arrived: " << totalCustomersArrived << std::endl;
    std::cout << "Number of customers who completed transactions: " << totalCustomersServed << std::endl;
    std::cout << "Average wait time for customers: "
        << (totalCustomersServed > 0 ? (double)totalWaitTime / totalCustomersServed : 0) << std::endl;
}
