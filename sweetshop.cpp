
#include "SweetShop.h"
#include<unistd.h>
using namespace std;
SweetShop::SweetShop()
{
    m_count = 0;
    loadCustomers();

}

SweetShop::~SweetShop()
{
    for (int i = 0; i < m_count; i++)
    {
        delete c3[i];
    }
}

void SweetShop::addCustomer()
{
    int customerType;
    cout << "\n\n\tWhat kind of Customer do you want to add?\n"
         << "\t\t------------------------\n"
         << "\t\t|1. Person\t\t|\n"
         << "\t\t|2. Company\t\t|\n"
         << "\t\t------------------------\n\t\t";
    cin >> customerType;
    customer* cust = nullptr;

    switch (customerType)
    {
    case 1:
        cust = new person();
        break;

    case 2:
        cust = new company();
        break;

    default:
        cout << "Invalid customer type.\n";
        return;
    }

    if (cust != nullptr)
    {
        cust->setdata();
        c3[m_count++] = cust;

        cout << "Customer added successfully.\n";
        cout << "Customer data:\n";
        cust->getdata();

        ofstream file("customers.txt", ios::app);
        if (file.is_open())
        {
            file << cust->getuserid() << " "; // Write the customer ID to the file

            if (dynamic_cast<person*>(cust) != nullptr)
            {
                person* p = static_cast<person*>(cust);
                file << "P " << p->getfullname() << " " << p->getbillingaddress() << "\n";
            }
            else if (dynamic_cast<company*>(cust) != nullptr)
            {
                company* c = static_cast<company*>(cust);
                file << "C " << c->getlocation() << " " << c->getcompanyname() << "\n";
            }
            file.close();
            cout << "Customer data written to file.\n";
        }
        else
        {
            cout << "Unable to save customer information to file.\n";
        }
    }
}void SweetShop::loadCustomers()
{
    ifstream inFile("customers.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            customer* cust = nullptr;

            stringstream ss(line);
            int id;
            char type;
            ss >> id >> type;
            if (type == 'P')
            {
                cust = new person();
                person* p = static_cast<person*>(cust);

                string fullname, billingaddress;
                ss >> fullname >> billingaddress;

                p->setuserid(id);
                p->setname(fullname);
                p->setbillig_address(billingaddress);
            }
            else if (type == 'C')
            {
                cust = new company();
                company* c = static_cast<company*>(cust);

                string location, companyName;
                ss >> location >> companyName;

                c->setuserid(id);
                c->setlocation(location);
                c->setcompanyname(companyName);
            }

            if (cust != nullptr)
            {
                c3[m_count++] = cust;
            }
        }

        inFile.close();
    }
    else
    {
        cout << "Unable to open file.\n";
    }
}
void SweetShop::editCustomer(int id)
{
    if (m_count == 0)
    {
        cout << "No user exists." << endl;
        return;
    }

    bool edited = false;
    for (int i = 0; i < m_count; i++)
    {
        if (c3[i]->getuserid() == id)
        {
            c3[i]->setdata();
            edited = true;
        }
    }

    if (edited)
    {
        cout << "User edited successfully." << endl;
    }
    else
    {
        cout << "No user exists." << endl;
    }
}

void SweetShop::deleteCustomer(int id)
{
    if (m_count == 0)
    {
        cout << "No user exists." << endl;
        return;
    }

    bool deleted = false;
    for (int i = 0; i < m_count; i++)
    {
        if (c3[i]->getuserid() == id)
        {
            if (i == m_count - 1)
            {
                m_count--;
            }
            else
            {
                c3[i] = c3[m_count - 1];
                m_count--;
            }
            deleted = true;
            break;
        }
    }

    if (deleted)
    {
        cout << "User deleted successfully." << endl;
    }
    else
    {
        cout << "No user exists." << endl;
    }
}
void SweetShop::addOrder()
{
    int customerId;
    cout << "Enter the customer ID: ";
    cin >> customerId;

    customer* cust = nullptr;
    for (int i = 0; i < m_count; i++)
    {
        if (c3[i]->getuserid() == customerId)
        {
            cust = c3[i];
            break;
        }
    }
    if (cust == nullptr)
    {
        cout << "No customer found with the specified ID." << endl;
        return;
    }

    Order order;
    int numbSweets, orderID;
    cout << "Enter ID for the order: ";
    cin >> orderID;
    order.setOrderID(orderID);
    cout << "Enter the number of sweets in the order: ";
    cin >> numbSweets;

    for (int i = 0; i < numbSweets; i++)
    {
        int sweetId;
        cout << "Enter the ID of sweet " << (i + 1) << ": ";
        cin >> sweetId;

        Sweets* sweet = nullptr;
        for (int j = 0; j < numSweets; j++)
        {
            if (sweets[j].getId() == sweetId)
            {
                sweet = &sweets[j];
                break;
            }
        }

        if (sweet == nullptr)
        {
            cout << "No sweet found with the specified ID." << endl;
            continue;
        }

        if (sweet->getStockQuantity() == 0)
        {
            cout << "Sweet " << sweetId << " is out of stock." << endl;
            continue;
        }

        cout << "Available shapes for sweet " << sweetId << ":" << endl;
        for (int k = 0; k < sweet->getNumTrays(); k++)
        {
            cout << k + 1 << ". " << sweet->getTrayShape(k) << " (quantity: " << sweet->getTrayQuantity(k) << ")" << endl;
        }
        int shapeChoice;
        cout << "Enter the number of the shape from which you want to order: ";
        cin >> shapeChoice;

        if (shapeChoice < 1 || shapeChoice > sweet->getNumTrays())
        {
            cout << "Invalid shape choice. Please try again." << endl;
            i--;
            continue;
        }

        string sweetshape = sweet->getTrayShape(shapeChoice - 1);

        double quantityInStock = sweet->getTrayQuantity(shapeChoice - 1);
        if (quantityInStock == 0)
        {
            cout << "Sweet " << sweetId << " in shape " << shapeChoice << " is out of stock." << endl;
            continue;
        }

        double quantity;
        cout << "Enter the quantity of sweet " << sweetId << " from shape " << shapeChoice << ": ";
        cin >> quantity;

        if (quantity <= 0)
        {
            cout << "Invalid input. Quantity must be a positive number." << endl;
            i--;
            continue;
        }

        if (quantity > quantityInStock)
        {
            cout << "Insufficient quantity of sweet " << sweetId << " in shape " << shapeChoice << "." << endl;
            i--;
            continue;
        }

        sweet->reduceTrayQuantity(shapeChoice - 1, quantity);
        cout << "New quantity of sweet " << sweetId << " in shape " << shapeChoice << ": " << sweet->getTrayQuantity(shapeChoice - 1) << endl;

        order.addSweet(*sweet, quantity, sweetshape);
    }

    if (numOrders < MAX_ORDERS)
    {
        orders[numOrders++] = order;
        cout << "Order added successfully." << endl;
    }
    else
    {
        cout << "Maximum order limit reached. Cannot add more orders." << endl;
        return;
    }

    sleep(2);
}
void SweetShop::editOrder(int orderId)
{
    if (numOrders == 0)
    {
        cout << "No orders exist." << endl;
        return;
    }

    for (int i = 0; i < numOrders; i++)
    {
        if (orders[i].getOrderID() == orderId)
        {
            int numSweets;
            cout << "Enter the new number of sweets in the order: ";
            cin >> numSweets;

            orders[i].removeAllSweets();

            for (int j = 0; j < numSweets; j++)
            {
                int sweetId;
                cout << "Enter the ID of sweet " << (j + 1) << ": ";
                cin >> sweetId;

                Sweets* sweet = nullptr;
                for (int k = 0; k < numSweets; k++)
                {
                    if (sweets[k].getId() == sweetId)
                    {
                        sweet = &sweets[k];
                        break;
                    }
                }

                if (sweet == nullptr)
                {
                    cout << "No sweet found with the specified ID." << endl;
                    continue;
                }

                int quantity;
                int newstockquantity;
                cout << "Enter the quantity of sweet " << sweetId << ": ";
                cin >> quantity;


                orders[i].addSweet(*sweet, quantity,sweetshape);
            }

            cout << "Order edited successfully." << endl;
            return;
        }
    }

    cout << "No order found with the specified ID." << endl;
}

void SweetShop::deleteOrder(int orderId)
{
    if (numOrders == 0)
    {
        cout << "No orders exist." << endl;
        return;
    }

    for (int i = 0; i < numOrders; i++)
    {
        if (orders[i].getOrderID() == orderId)
        {
            if (i == numOrders - 1)
            {
                numOrders--;
            }
            else
            {
                orders[i] = orders[numOrders - 1];
                numOrders--;
            }

            cout << "Order deleted successfully." << endl;
            return;
        }
    }

    cout << "No order found with the specified ID." << endl;
}

void SweetShop::displayOrders() const
{
    if (numOrders == 0)
    {
        cout << "No orders exist." << endl;
        return;
    }

    cout << "Orders:\n";
    for (int i = 0; i < numOrders; i++)
    {
        orders[i].displayOrderDetails();
        cout << endl;
    }
}
//////////////////////////////////////////////
void SweetShop::addCategory()
{
    int id;
    string name;
    double pricePerKilo;

    cout << "Enter the ID of the sweet: ";
    cin >> id;
    for (int i = 0; i < numSweets; i++)
    {
        if (sweets[i].getId() == id)
        {
            cout << "Sweet category with the specified ID already exists." << endl;
            return;
        }
    }
    cout << "Enter the name of the sweet: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the price per kilo of the sweet: ";
    cin >> pricePerKilo;

    if (numSweets < MAX_SWEETS)
    {
        sweets[numSweets].setId(id);
        sweets[numSweets].setName(name);
        sweets[numSweets].setPrice(pricePerKilo);
        sweets[numSweets].setstockQuantity(0);
        numSweets++;
        cout << "Sweet category added successfully." << endl;
    }
    else
    {
        cout << "Maximum sweets limit reached. Cannot add more sweets." << endl;
    }
}

void SweetShop::addSweet()
{
    int id;
    double quantity;
    string trayShape;
    double sweetQuantityInTray;

    cout << "Enter the ID of the sweet: ";
    cin >> id;

    for (int i = 0; i < numSweets; i++)
    {
        if (sweets[i].getId() == id)
        {
            // Sweet found, add tray
            cout << "Enter the shape of the tray: ";
            cin.ignore();
            getline(cin, trayShape);
            cout << "Enter the quantity of sweet in the tray: ";
            cin >> sweetQuantityInTray;
            sweets[i].setstockQuantity(sweets[i].getStockQuantity()+sweetQuantityInTray);
            sweets[i].addTray(trayShape, sweetQuantityInTray);

            cout << "Tray added successfully." << endl;
            return;
        }
    }

    // Sweet not found
    cout << "No sweet found with the specified ID." << endl;
}

void SweetShop::editSweet(int id)
{
    bool edited = false;
    for (int i = 0; i < numSweets; i++)
    {
        if (sweets[i].getId() == id)
        {
            string name;
            double price;

            cout << "Enter the new name of the sweet: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the new price of the sweet: ";
            cin >> price;

            sweets[i].setName(name);
            sweets[i].setPrice(price);
            edited = true;
            break;
        }
    }

    if (edited)
    {
        cout << "Sweet edited successfully." << endl;
    }
    else
    {
        cout << "No sweet found with the specified ID." << endl;
    }
}

void SweetShop::deleteSweet(int id)
{
    int foundIndex = -1;
    for (int i = 0; i < numSweets; i++)
    {
        if (sweets[i].getId() == id)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        for (int i = foundIndex; i < numSweets - 1; i++)
        {
            sweets[i] = sweets[i + 1];
        }

        numSweets--;
        cout << "Sweet deleted successfully." << endl;
    }
    else
    {
        cout << "No sweet found with the specified ID." << endl;
    }
}

void SweetShop::displaySweets() const
{
    if (numSweets == 0)
    {
        cout << "\t\t\t[No sweets found]." << endl;
        return;
    }

    cout <<"\n\t->>>Sweets List:\t   " << endl;
    for (int i = 0; i < numSweets; i++)
    {
        cout <<"\t\t----------------------------------"<<endl;
        cout <<"\t\t|ID: " << sweets[i].getId() << endl;
        cout <<"\t\t|Name: " << sweets[i].getName() << endl;
        cout <<"\t\t|Price:" << sweets[i].getPrice() << endl;
        cout <<"\t\t|Quantity:" << sweets[i].getStockQuantity() << endl;
        cout <<"\t\t|Trays:" << endl;

        int numTrays = sweets[i].getNumTrays();
        if (numTrays == 0)
        {
            cout << "\t\t|  [No trays found]" << endl;
        }
        else
        {
            for (int j = 0; j < numTrays; j++)
            {
                cout << "\t\t|  - Shape: " << sweets[i].getTrayShape(j) << ", Quantity of sweet in tray: " << sweets[i].getTrayQuantity(j) << endl;
            }
        }

        cout <<"\t\t----------------------------------"<<endl;
    }
}
void SweetShop::deleteTray()
{
    int sweetId;
    cout << "Enter the ID of the sweet from which to delete a tray: ";
    cin >> sweetId;

    // Search for the sweet with the specified ID
    int sweetIndex = -1;
    for (int i = 0; i < numSweets; i++)
    {
        if (sweets[i].getId() == sweetId)
        {
            sweetIndex = i;
            break;
        }
    }

    if (sweetIndex == -1)
    {
        cout << "No sweet found with the specified ID." << endl;
        return;
    }

    Sweets& sweet = sweets[sweetIndex];
    int numTrays = sweet.getNumTrays();
    if (numTrays == 0)
    {
        cout << "The sweet has no trays to delete." << endl;
        return;
    }

    cout << "Available trays for sweet " << sweetId << ":" << endl;
    for (int i = 0; i < numTrays; i++)
    {
        cout << i + 1 << ". " << sweet.getTrayShape(i) << endl;
    }

    int trayIndex;
    cout << "Enter the index of the tray to delete: ";
    cin >> trayIndex;

    if (trayIndex < 1 || trayIndex > numTrays)
    {
        cout << "Invalid tray index." << endl;
        return;
    }

    sweet.removeTray(trayIndex - 1);

    // Print a success message
    cout << "Tray removed successfully from sweet " << sweetId << "." << endl;
}
double SweetShop::CalcTotalProfitLoss() const
{
    double totalProfitLoss = 0.0;
    for (int i = 0; i < numOrders; i++)
    {
        const Order& order = orders[i];
        double orderTotalPrice = order.getTotalPrice();
        double orderCost = 0.0;
        for (int j = 0; j < numSweets; j++)
        {
            const Sweets& sweet = order.getSweets()[j];
            orderCost += sweet.calculateCost();
        }
        double orderProfitLoss = orderTotalPrice - orderCost;
        totalProfitLoss += orderProfitLoss;
    }
    return totalProfitLoss;
}
void SweetShop::ShowProfit() const
{
    double totalProfit = 0.0;
    for (int i = 0; i < numOrders; i++)
    {
        double orderProfit = 0.0;
        const Sweets* orderSweets = orders[i].getSweets();
        for (int j = 0; j < numSweets; j++)
        {
            const Sweets& sweet = orderSweets[j];
            orderProfit += sweet.calculateCost();
        }

        totalProfit += orderProfit;
        cout << "Profit for Order ID " << orders[i].getOrderID() << ": " << orderProfit << endl;
    }

    cout << "Total Profit: " << totalProfit << endl;
}

void SweetShop::ShowLoss() const
{
    double totalLoss = 0.0;
    for (int i = 0; i < numOrders; i++)
    {
        double orderLoss = 0.0;
        const Sweets* orderSweets = orders[i].getSweets();
        for (int j = 0; j < numSweets; j++)
        {
            const Sweets& sweet = orderSweets[j];
            orderLoss += sweet.getPrice() * (sweet.getStockQuantity()-quantity);

        }

        totalLoss += orderLoss;
        cout << "Loss for Order ID " << orders[i].getOrderID() << ": " << orderLoss << endl;
    }

    cout << "Total Loss: " << totalLoss << endl;
}

void SweetShop::displaycustomers()
{
    if(m_count==0)
    {
        cout<<"\n\t\t\tSORRY,NO CUSTOMERS HAD BEEN ADDED.......";
    }
    else
    {
        for (int i = 0; i < m_count; i++)
        {
            c3[i]->getdata();
        }
    }

}
void SweetShop::addpayment(int orderId)
{
    if (numOrders == 0)
    {
        cout << "No orders exist to pay." << endl;
        return;
    }

    for (int i = 0; i < numOrders; i++)
    {
        if (orders[i].getOrderID() == orderId)
        {
            int ch;
            cout<<"CHOOSE THE WAY TO PAY ORDER"<<endl;
            cout<<"1-CASH  2-CREDIT  3-CHECK "<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1:
                p1[i]=new cash();
                p1[i]->set_info();
                cout<<"\n\t\t\t paid successfully...";
                break;
            case 2:
                p1[i]=new credit();
                p1[i]->set_info();
                cout<<"\n\t\t\t paid successfully...";
                break;
            case 3:
                p1[i]=new check();
                p1[i]->set_info();
                cout<<"\n\t\t\t paid successfully...";
                break;



            }
        }
    }
}
void SweetShop::displayinvoice()
{
    int id;
    cout<<"enter id of customer";
    cin>>id;
    if (m_count == 0)
    {
        cout << "No user exists." << endl;
        return;
    }
    for (int i = 0; i < m_count; i++)
    {
        if (c3[i]->getuserid() == id)
        {
            int orderid;
            cout<<"enter id of order";
            cin>>orderid;
            if (numOrders == 0)
            {
                cout << "No orders exist." << endl;
                return;
            }
            c3[i]->getdata();

            for (int i = 0; i < numOrders; i++)
            {
                if (orders[i].getOrderID() == orderid)
                {



                    cout<<"\n-------------------------------------------------------------------------------------\n";
                    orders[i].displayOrderDetails();
                }
            }

        }
    }
}
/*void SweetShop::saveCustomerDataToFile()
{
    std::ofstream outfile("customers.txt");
    if (!outfile.is_open())
    {
        std::cerr << "Error: Cannot open file for writing.\n";
        return;
    }

    outfile << m_count << "\n";

    for (int i = 0; i < m_count; i++)
    {
        customer* cust = c3[i];
        outfile << cust->getuserid() << "," << cust->getName() << "," << cust->getEmail() << "\n";
    }

    outfile.close();
}

void SweetShop::loadCustomerDataFromFile()
{
    std::ifstream infile("customers.txt");
    if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open file for reading.\n";
        return;
    }

    int count;
    infile >> count;

    for (int i = 0; i < count; i++)
    {
        int id;
        std::string name, email;

        infile >> id;
        infile.ignore();
        std::getline(infile, name, ',');
        std::getline(infile, email);

        c3[m_count++] = new person(id, name, email);
    }

    infile.close();
}*/
