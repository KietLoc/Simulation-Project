#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include "Customer.h"

class Server {
private:
    int serverID;
    bool isBusy;
    int transactionTime;
    std::shared_ptr<Customer> currentCustomer;

public:
    Server(int id);
    bool isFree() const;
    void assignCustomer(std::shared_ptr<Customer> customer, int transactionTime);
    void updateTransactionTime(int& totalWaitTime, int& totalCustomersServed);
};

#endif
