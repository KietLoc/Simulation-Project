#include "Server.h"

Server::Server(int id) : serverID(id), isBusy(false), transactionTime(0), currentCustomer(nullptr) {}

bool Server::isFree() const {
    return !isBusy;
}

void Server::assignCustomer(std::shared_ptr<Customer> customer, int transactionTime) {
    isBusy = true;
    this->transactionTime = transactionTime;
    currentCustomer = customer;
}

void Server::updateTransactionTime(int& totalWaitTime, int& totalCustomersServed) {
    if (isBusy) {
        transactionTime--;
        if (transactionTime == 0) {
            totalWaitTime += currentCustomer->getWaitTime();
            totalCustomersServed++;
            isBusy = false;
            currentCustomer = nullptr;
        }
    }
}
