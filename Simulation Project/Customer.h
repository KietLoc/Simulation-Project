#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int customerID;
    int waitTime;

public:
    Customer(int id);
    int getCustomerID() const;
    void updateWaitTime();
    int getWaitTime() const;
};

#endif
