#include "CustomerQueue.h"

CustomerQueue::CustomerQueue(int arrivalTime) : nextCustomerID(1), timeBetweenArrivals(arrivalTime) {}

void CustomerQueue::addCustomer(int currentTime) {
    if (currentTime % timeBetweenArrivals == 0) {
        customerQueue.push(std::make_shared<Customer>(nextCustomerID++));
    }
}

std::shared_ptr<Customer> CustomerQueue::removeCustomer() {
    if (!customerQueue.empty()) {
        auto customer = customerQueue.front();
        customerQueue.pop();
        return customer;
    }
    return nullptr;
}

void CustomerQueue::updateWaitTimes() {
    size_t size = customerQueue.size();
    for (size_t i = 0; i < size; i++) {
        auto customer = customerQueue.front();
        customerQueue.pop();
        customer->updateWaitTime();
        customerQueue.push(customer);
    }
}

int CustomerQueue::getQueueSize() const {
    return customerQueue.size();
}
