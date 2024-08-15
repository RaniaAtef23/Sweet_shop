#include "order.h"
#include <iostream>

Order::Order()
{
    orderID = 0;
    numSweets = 0;
}

Order::~Order()
{
}

int Order::getOrderID() const
{
    return orderID;
}

void Order::setOrderID(int id)
{
    orderID = id;
}

double Order::getTotalPrice() const
{
    double totalPrice = 0.0;
    for (int i = 0; i < numSweets; i++)
    {
        totalPrice += sweets[i].getPrice()*sweets[i].getQuantity();
    }
    return totalPrice;
}

void Order::displayOrderDetails() const
{
    cout << "Order ID: " << orderID << endl;
    cout << "Customer: " << customer.getname() << endl;

    if (numSweets == 0)
    {
        cout << "No sweets in the order." << endl;
    }
    else
    {
        cout << "Sweets in the order:" << endl;
        for (int i = 0; i < numSweets; i++)
        {
            cout << "- " << sweets[i].getName() << " (Quantity: " << sweets[i].getQuantity() << ")" << endl;
            cout<<"- sweetshape | "<<sweets[i].getsweetshape()<<endl;
        }
    }

    cout << "Total Price: " << getTotalPrice() << endl;
}

void Order::addSweet(const Sweets& sweet, double quantity,string sweetshape)
{
    if (numSweets < MAX_SWEETS)
    {
        sweets[numSweets] = sweet;
        sweets[numSweets].setQuantity(quantity);
        sweets[numSweets].setsweetshape(sweetshape);

        numSweets++;
    }
    else
    {
        cout << "Cannot add more sweets to the order. Maximum limit reached." << endl;
    }
}

void Order::removeSweet(int index)
{
    if (index >= 0 && index < numSweets)
    {
        for (int i = index; i < numSweets - 1; i++)
        {
            sweets[i] = sweets[i + 1];
        }
        numSweets--;
    }
    else
    {
        cout << "Invalid index. Cannot remove sweet from the order." << endl;
    }
}

void Order::removeAllSweets()
{
    numSweets = 0;
}
const Sweets* Order::getSweets() const
{
    return sweets;
}

