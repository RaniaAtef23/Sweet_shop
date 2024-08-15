#ifndef ORDER_H
#define ORDER_H

#include "sweets.h"
#include "customer.h"

class Order
{
private:
    int orderID;
    static const int MAX_SWEETS = 100;
    Sweets sweets[MAX_SWEETS];
    int numSweets;
    customer customer;
    int quantity;

public:
    Order();
    ~Order();
    int getOrderID() const;
    void setOrderID(int id);
    double getTotalPrice() const;
    void displayOrderDetails() const;
    void addSweet(const Sweets& sweet, double quantity,string sweetshape);
    void removeSweet(int index);
    void removeAllSweets();

    const Sweets* getSweets() const;

};

#endif  // ORDER_H
