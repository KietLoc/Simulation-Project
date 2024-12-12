#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <vector>
#include "Server.h"

class ServerList {
private:
    std::vector<Server> servers;
    int totalCustomersServed;
    int totalWaitTime;

public:
    ServerList(int numServers);
    int findFreeServer();
    void updateServers();
    void assignCustomerToFreeServer(std::shared_ptr<Customer> customer, int transactionTime);
    int getTotalCustomersServed() const;
    int getTotalWaitTime() const;
};

#endif
