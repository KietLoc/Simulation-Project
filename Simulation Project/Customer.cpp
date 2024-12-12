#include "Customer.h"

Customer::Customer(int id) : customerID(id), waitTime(0) {}

int Customer::getCustomerID() const {
    return customerID;
}

void Customer::updateWaitTime() {
    waitTime++;
}

int Customer::getWaitTime() const {
    return waitTime;
}
