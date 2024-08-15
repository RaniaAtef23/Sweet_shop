#include "customer.h"
#include<iostream>
using namespace std;
customer::customer()
{
    id=0;
}

customer::~customer()
{
    //dtor
}
void customer::setdata()
{
    cout << "Enter customer name: ";
    getline(cin >> ws, name);

    while (name.empty()) {
        cout << "Customer name cannot be empty. Please enter customer name: ";
        getline(cin >> ws, name);
    }

    cout << "Enter customer ID: ";
    cin >> id;

    while (cin.fail() || id < 0) {
        cout << "Invalid customer ID. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> id;
    }

    cout << "Enter customer address: ";
    getline(cin >> ws, address);

    while (address.empty()) {
        cout << "Customer address cannot be empty. Please enter customer address: ";
        getline(cin >> ws, address);
    }
}

void customer::getdata()
{
    cout << "| " << setw(12) << left << "Name:" << setw(30) << left << name
         << setw(15) << left << "ID:" << setw(10) << left << id
         << setw(25) << left << "Address:" << setw(30) << left << address << "|\n";
    cout << "------------------------------------------------------------------\n";
}
int customer::getuserid()
{
    return id;
}
void customer::setuserid(int idn)
{
    id = idn;
}
void customer::setname(const string& newname)
{
    name = newname;
}

string customer::getname() const
{
    return name;
}
