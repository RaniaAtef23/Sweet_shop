#ifndef SWEETS_H
#define SWEETS_H
#include "customer.h"
#include <iostream>
using namespace std;
const int MAX_TRAYS = 100;
class Sweets
{
public:
    Sweets();
    ~Sweets();

    friend istream& operator>>(istream& in, Sweets& p);
    friend ostream& operator<<(ostream& out, const Sweets& p);

    void addQuantity(double amount);
    void reduceQuantity(double amount);

    double getPrice() const;
    double getQuantity() const;
    int getId() const;
    void setName(const string& name);
    void setPrice(double price);
    void setQuantity(double quantity1);
    void setstock(double quantitystock);
    void setId(int id);
    double calculateCost() const;
    string getName() const;
    void print1();
    double getStockQuantity() const;
    void setCustomer(const customer& customer);
    void setstockQuantity(double setstockQuantity1);
    void setsweetshape(string sh);
    string getsweetshape()const;

    int getNumTrays() const;
    string getTrayShape(int index) const;
    double getTrayQuantity(int index) const;
    void addTray(string shape, double sweetQuantityInTray);
    void reduceTrayQuantity(int index, double amount);
    void removeTray(int index);

private:
    int id;
    int number;
    string name;
    double price;
    string type;
    double quantity;
    double stock_quantity;
    string sweet_shape;

    string trayShapes[MAX_TRAYS];
    int numShapes;
    double trayQuantities[MAX_TRAYS];
    int numTrays;
};

#endif
