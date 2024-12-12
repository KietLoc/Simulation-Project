#include "ServerList.h"

ServerList::ServerList(int numServers) : totalCustomersServed(0), totalWaitTime(0) {
    for (int i = 0; i < numServers; i++) {
        servers.emplace_back(i + 1);
    }
}

int ServerList::findFreeServer() {
    for (int i = 0; i < servers.size(); i++) {
        if (servers[i].isFree()) {
            return i;
        }
    }
    return -1;
}

void ServerList::updateServers() {
    for (auto& server : servers) {
        server.updateTransactionTime(totalWaitTime, totalCustomersServed);
    }
}

void ServerList::assignCustomerToFreeServer(std::shared_ptr<Customer> customer, int transactionTime) {
    int index = findFreeServer();
    if (index != -1) {
        servers[index].assignCustomer(customer, transactionTime);
    }
}

int ServerList::getTotalCustomersServed() const {
    return totalCustomersServed;
}

int ServerList::getTotalWaitTime() const {
    return totalWaitTime;
}
