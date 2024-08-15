
#ifndef SWEETSHOP_H
#define SWEETSHOP_H
#include <sstream>
#include<iostream>
#include<string>
#include "person.h"
#include "company.h"
#include "Sweets.h"
#include "Order.h"
#include"payment.h"
#include"cash.h"
#include"credit.h"
#include"check.h"
#include<iostream>
#include <fstream>
const int MAX_CUSTOMERS = 100;
const int MAX_ORDERS = 100;
const int MAX_SWEETS = 100;
const int MAX_PAYMENT=100;

using namespace std;
class SweetShop
{
public:
    SweetShop();
    ~SweetShop();

    void addCustomer();
    void editCustomer(int id);
    void deleteCustomer(int id);
    void displaycustomers();

    void loadCustomers();
    void writeToFile(ofstream& file, customer* cust);


    void addSweet();
    void editSweet(int id);
    void deleteSweet(int id);
    void displaySweets() const;
    void deleteTray();

    void addOrder();
    void editOrder(int id);
    void deleteOrder(int id);
    void displayOrders() const;

    double CalcTotalProfitLoss() const;
    void ShowProfit() const;
    void ShowLoss() const;
    void addpayment(int orderId);
    void displayinvoice();

    void addCategory();

    void loadCustomerDataFromFile();
    void saveCustomerDataToFile();
private:
    int m_count;
    customer* c3[MAX_CUSTOMERS];
    int numCustomers;

    Sweets sweets[MAX_SWEETS];
    int numSweets;

    Order orders[MAX_ORDERS];
    int numOrders;
    payment *p1[100];
    double quantity;

    string sweetshape;
};

#endif // SWEETSHOP_H
