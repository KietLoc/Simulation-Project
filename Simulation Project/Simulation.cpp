#include "Simulation.h"
#include <iostream>
#include <iomanip>

void runSimulation(int simulationTime, int numServers, int transactionTime, int arrivalTime) {
    ServerList serverList(numServers);
    CustomerQueue customerQueue(arrivalTime);

    int totalCustomersArrived = 0;
    std::cout << "---------------------------------------------------------------\n";

    for (int currentTime = 0; currentTime < simulationTime; currentTime++) {
        // Update servers
        serverList.updateServers();

        // Update wait times in the queue
        customerQueue.updateWaitTimes();

        // Add new customers to the queue based on arrival time
        if (currentTime % arrivalTime == 0) {
            customerQueue.addCustomer(currentTime);
            totalCustomersArrived++;
            std::cout << "Customer number: " << totalCustomersArrived << " arrived at time unit: " << currentTime << "\n";
        }

        // Assign customers from the queue to free servers
        while (auto customer = customerQueue.removeCustomer()) {
            int freeServerIndex = serverList.findFreeServer();
            if (freeServerIndex != -1) {
                serverList.assignCustomerToFreeServer(customer, transactionTime);
                std::cout << "From server: " << freeServerIndex + 1
                    << " customer " << customer->getCustomerID()
                    << " departed at time unit " << currentTime + transactionTime << "\n";
            }
            else {
                // No free server; return the customer to the queue
                customerQueue.addCustomer(customer->getCustomerID());
                break;
            }
        }
    }

    // Final statistics
    int totalWaitTime = serverList.getTotalWaitTime();
    int totalCustomersServed = serverList.getTotalCustomersServed();
    int remainingCustomers = customerQueue.getQueueSize();

    double avgWaitTime = remainingCustomers > 0 ? (double)totalWaitTime / remainingCustomers : 0.0;

    std::cout << "---------------------------------------------------------------\n";
    std::cout << "Number of customers left in queue: " << remainingCustomers << "\n";
    std::cout << "Number of customers that arrived: " << totalCustomersArrived << "\n";
    std::cout << "Number of customers who completed a transaction: " << totalCustomersServed << "\n";
    std::cout << "Average wait time for customers in the queue: "
        << std::fixed << std::setprecision(5) << avgWaitTime << "\n";
}
