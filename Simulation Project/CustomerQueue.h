#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include <queue>
#include <memory>
#include "Customer.h"

class CustomerQueue {
private:
    std::queue<std::shared_ptr<Customer>> customerQueue;
    int nextCustomerID;
    int timeBetweenArrivals;

public:
    CustomerQueue(int arrivalTime);
    void addCustomer(int currentTime);
    std::shared_ptr<Customer> removeCustomer();
    void updateWaitTimes();
    int getQueueSize() const;
};

#endif
