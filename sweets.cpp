
#include "sweets.h"

Sweets::Sweets()
{
    id = 0;
    number = 0;
    name = "";
    price = 0.0;
    type = "";
    numTrays=0;
    for (int i = 0; i < MAX_TRAYS; i++)
    {
        trayShapes[i] = "";
        trayQuantities[i] = 0.0;
    }

}

Sweets::~Sweets()
{
    // Destructor
}

istream& operator>>(istream& in, Sweets& p)
{
    cout << "id| ";
    in >> p.id;
    cout << "number| ";
    in >> p.number;
    cout << "name | ";
    in >> p.name;
    cout << "price | ";
    in >> p.price;
    cout << "type | ";
    in >> p.type;
    cout << "stock quantity | ";
    in >> p.stock_quantity;

    return in;
}

ostream& operator<<(ostream& out, const Sweets& p)
{
    out << "id| " << p.id << "\t";
    out << "number| " << p.number << "\t";
    out << "name | " << p.name << "\t";
    out << "price | " << p.price << "\t";
    out << "type | " << p.type << "\t";
    out << "stock quantity | " << p.stock_quantity << "\t";
    out<<"sweet shape | "<<p.sweet_shape<<"\t";

    return out;
}

void Sweets::addQuantity(double amount)
{
    quantity += amount;
}

void Sweets::reduceQuantity(double amount)
{
    if (amount <= quantity)
        quantity -= amount;
    else
        cout << "Insufficient quantity." << endl;
}

double Sweets::getPrice() const
{
    return price;
}

double Sweets::getQuantity() const
{
    return quantity;
}

int Sweets::getId() const
{
    return id;
}

void Sweets::setName(const string& name)
{
    this->name = name;
}

void Sweets::setPrice(double price)
{
    this->price = price;
}

void Sweets::setQuantity(double quantity1)
{
    this->quantity = quantity1;
}
void Sweets::setstockQuantity(double setstockQuantity1)
{
    stock_quantity =setstockQuantity1;
}
void Sweets::setId(int id)
{
    this->id = id;
}

double Sweets::calculateCost() const
{
    return price * quantity;
}

string Sweets::getName() const
{
    return name;
}

void Sweets::print1()
{
    cout << "\n";
    cout << "id| " << id << "\t";
    cout << "number| " << number << "\t";
    cout << "name | " << name << "\t";
    cout << "price | " << price << "\t";
    cout << "type | " << type << "\t";
    cout << "stock quantity | " << stock_quantity << "\t";
}

double Sweets::getStockQuantity()const
{
    return stock_quantity ;
}
void Sweets::setstock(double quantitystock)
{
    stock_quantity=quantitystock;
}
void Sweets::setsweetshape(string sh)
{
    sweet_shape=sh;
}
string Sweets::getsweetshape()const
{
    return sweet_shape;
}

int Sweets::getNumTrays() const
{
    return numTrays;
}

string Sweets::getTrayShape(int index) const
{
    if (index < 0 || index >= numTrays) {
        return "";
    }
    return trayShapes[index];
}

double Sweets::getTrayQuantity(int index) const
{
    if (index < 0 || index >= numTrays) {
        return 0.0;
    }
    return trayQuantities[index];
}

void Sweets::addTray(string shape, double sweetQuantityInTray)
{
    if (numTrays >= MAX_TRAYS) {
        return;
    }
    trayShapes[numTrays] = shape;
    trayQuantities[numTrays] = sweetQuantityInTray;
    numTrays++;
    /*

    stock_quantity += sweetQuantityInTray;
    */
}

void Sweets::reduceTrayQuantity(int index, double amount)
{
    if (index < 0 || index >= numTrays) {
        return;
    }

    double currentQuantity = trayQuantities[index];
    if (amount > currentQuantity) {
        trayQuantities[index] = 0;
    } else {
        trayQuantities[index] -= amount;
    }

    double totalQuantity = 0;
    for (int i = 0; i < numTrays; i++) {
        totalQuantity += trayQuantities[i];
    }
    stock_quantity = totalQuantity;
}
void Sweets::removeTray(int index)
{
    if (index < 0 || index >= numTrays)
    {
        cout << "Invalid tray index." << endl;
        return;
    }

    string removedShape = trayShapes[index];
    double removedQuantity = trayQuantities[index];

    for (int i = index; i < numTrays - 1; i++)
    {
        trayShapes[i] = trayShapes[i + 1];
        trayQuantities[i] = trayQuantities[i + 1];
    }

    trayShapes[numTrays - 1] = "";
    trayQuantities[numTrays - 1] = 0;
    numTrays--;

    cout << "Tray with shape " << removedShape << " and quantity " << removedQuantity
         << " removed successfully." << endl;
}
