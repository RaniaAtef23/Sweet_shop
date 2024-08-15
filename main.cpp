

#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "SweetShop.h"
#include "customer.h"
#include "person.h"
#include "company.h"
#include"order.h"
using namespace std;
enum orderstatus {neW=0,hold=1,paid=2,canceled=3};
orderstatus s6;
SweetShop cm;
int choice;
Order o2;
enum MenuOption
{
    ADMIN = 1,
    CUSTOMER = 2,
    EXIT = 0
};

enum AdminOption
{
    CUSTOMER_MANAGEMENT = 1,
    PRODUCT_MANAGEMENT = 2,
    SHOW_PROFIT_AND_LOSS = 3
};

enum CustomerOption
{
    SHOW_PRODUCTS_CUSTOMER = 1,
    MAKE_ORDER_CUSTOMER = 2
};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
SweetShop c1;

void printline(string s, bool lo = true)
{
    cout << s << (lo ? "\n" : "\t");
}
void print_nchars_line(int n, char c)
{
    for(int i=0; i<n; ++i)
    {
        cout<<c;
    }
    cout<<"\n";
}
void welcome_screen(bool yes)
{
    SetConsoleTextAttribute(h, 15);
    cout<<"\t\t";
    print_nchars_line(66,'-');
    cout<<"\t\t|\t\t\t\t\t\t\t\t |\n\t\t|\t\t\t\t\t\t\t\t |\n";
    cout<<"\t\t|\t     (WELCOME TO OUR SWEET SHOP APPLICATION)\t\t |\n";
    SetConsoleTextAttribute(h, 11);
    cout<<"\t\t|\tis to efficiently manage and streamline the operations   |\n\t\t|\t \t    of a sweet shop business\t\t         |\n";
    cout<<"\t\t|\t\t\t\t\t\t\t\t |\n\t\t|\t\t\t\t\t\t\t\t |\n";
    SetConsoleTextAttribute(h, 15);
    cout<<"\t\t";
    print_nchars_line(66,'-');
    SetConsoleTextAttribute(h, 11);
    cout << "\t\t\t\t                    )  (\n";
    cout << "\t\t\t\t                   (   )\n";
    cout << "\t\t\t\t                    ) (\n";
    cout << "\t\t\t\t                _______)\n";
    cout << "\t\t\t\t         _..----'---__\n";
    cout << "\t\t\t\t       ,'             `.\n";
    cout << "\t\t\t\t      /                 \\\n";
    cout << "\t\t\t\t     |                 |\n";
    cout << "\t\t\t\t     |    SWEET SHOP   |\n";
    cout << "\t\t\t\t     |                 |\n";
    cout << "\t\t\t\t     |_________________|\n";
    cout<<endl<<endl;
    cout<<"\t\t\t\t";
    system("pause");
    system("cls");
}
void customermanagement()
{
    int c = -1;

    int id;


    while (c != 0)
    {
        cout << endl << "\t";
        cout << "\t\t**********************************************" << endl;
        cout << "\t\t\t*\tCUSTOMER INFORMATION MANAGEMENT       *\n\t";
        cout << "\t\t**********************************************" << endl;
        cout << "\t\t\t*\t[1] Add a new Customer\t\t     *" << endl;
        cout << "\t\t\t*\t[2] Edit a Customer\t\t     *" << endl;
        cout << "\t\t\t*\t[3] Delete a Customer\t\t     *" << endl;
        cout << "\t\t\t*\t[4] List all Customers\t\t     *" << endl;
        cout << "\t\t\t*\t[0] Back to Previous menu\t     *" << endl;
        cout << "\t\t\t**********************************************" << endl;
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cm.addCustomer();
            cout << "Customer added successfully." << endl;
            sleep(2);
            system("cls");
            break;
        case 2:
            cout << "__________________________________________________________________" << endl;
            cout << "|\t\tENTER ID OF THE CUSTOMER TO EDIT: \t\t |" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << "\t\t\t\t ";
            cin >> id;
            cm.editCustomer(id);
            sleep(2);
            system("cls");
            break;
        case 3:
            cout << "__________________________________________________________________" << endl;
            cout << "|\t\tENTER ID OF THE CUSTOMER TO DELETE: \t\t |" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << "\t\t\t\t ";
            cin >> id;
            cm.deleteCustomer(id);
            sleep(2);
            system("cls");
            break;
        case 4:
            system("cls");
            cm.displaycustomers();

            sleep(1);
            char choice;
            cout<<"BACK TO MAIN MANUE(y/n)?";
            cin>>choice;
            if(choice=='y')
            {
                system("cls");

                return;
            }
            system("cls");
            break;
        case 0:
            c = 0;
            break;
        default:
            cout << "\t";
            print_nchars_line(49, '-');
            cout << "\t|\t\tInvalid Option!!\t\t|" << endl;
            cout << "\t";
            print_nchars_line(49, '-');
            sleep(2);
            system("cls");
            break;
        }
    }
}
void manageSweets()
{
    int choice = -1;
    int id;

    while (choice != 0)
    {
        cout << "\t\t\t\t\t       ) ( \n";
        cout << "\t\t\t\t\t    ( ( ) ) \n";
        cout << "\t\t\t\t\t     )   ( \n";
        cout << "\t\t\t\t\t  (_________) \n";
        cout << "\t\t\t\t\t   |       | \n";
        cout << "\t\t\t\t\t   | Sweet | \n";
        cout << "\t\t\t\t\t   |_______| \n";
        cout << endl << "\t";
        while (choice != 0)
        {
            cout << "\t\t----------------------------------------------" << endl;
            cout << "\t\t\t|\t SWEET MANAGEMENT         \t     |\n\t";
            cout << "\t\t----------------------------------------------" << endl;
            cout << "\t\t\t|\t[1] Add New Category\t\t    |" << endl;
            cout << "\t\t\t|\t[2] Add a Sweet Tray\t\t     |" << endl;
            cout << "\t\t\t|\t[3] Edit a Sweet\t\t     |" << endl;
            cout << "\t\t\t|\t[4] Delete a Sweet Category\t\t     |" << endl;
            cout << "\t\t\t|\t[5] Delete a Sweet Tray\t\t     |" << endl;
            cout << "\t\t\t|\t[6] List all Sweets\t\t     |" << endl;
            cout << "\t\t\t|\t[0] Back to Previous menu\t     |" << endl;
            cout << "\t\t\t----------------------------------------------" << endl;
            cout << "\t\t\tEnter your choice: ";
            cin >> choice;
            system("cls");

            switch (choice)
            {
            case 1:
                cm.addCategory();
                cout << "Category added successfully." << endl;
                sleep(2);
                system("cls");
                break;
            case 2:
                cm.addSweet();
                cout << "Tray added successfully." << endl;
                sleep(2);
                system("cls");
                break;
            case 3:
                cout << "__________________________________________________________________" << endl;
                cout << "|\t\tENTER ID OF THE SWEET TO EDIT:\t\t\t |" << endl;
                cout << "__________________________________________________________________" << endl;
                cout << "\t\t\t\t ";
                cin >> id;
                cm.editSweet(id);
                sleep(2);
                system("cls");
                break;
            case 4:
                cout << "__________________________________________________________________" << endl;
                cout << "|\t\tENTER ID OF THE SWEET TO DELETE:\t\t |" << endl;
                cout << "__________________________________________________________________" << endl;
                cout << "\t\t\t\t ";
                cin >> id;
                cm.deleteSweet(id);
                sleep(2);
                system("cls");
                break;
            case 5:
                cm.deleteTray();
                sleep(2);
                system("cls");
                break;
            case 6:
                cm.displaySweets();
                sleep(2);
                char choice;
                cout << "\nBACK TO MAIN MENU (y/n)? ";
                cin >> choice;
                if (choice == 'y')
                {
                    system("cls");
                    return;
                }
                break;
            case 0:
                choice = 0;
                break;
            default:
                cout << "\t";
                print_nchars_line(49, '-');
                cout << "\t|\t\tInvalid Option!!\t\t|" << endl;
                cout << "\t";
                print_nchars_line(49, '-');
                sleep(2);
                system("cls");
                break;
            }
        }
    }
}
void showProfitAndLossSubMenu()
{
    int choice = -1;
    while (choice != 0)
    {
        cout << endl << "\t";
        cout << "\t\t----------------------------------------------" << endl;
        cout << "\t\t\t|\t SHOW PROFIT AND LOSS            \t|\n\t";
        cout << "\t\t----------------------------------------------" << endl;
        cout << "\t\t\t|\t[1] Show Total Profit\t\t     |" << endl;
        cout << "\t\t\t|\t[2] Show Total Loss\t\t     |" << endl;
        cout << "\t\t\t|\t[0] Back to Previous menu\t     |" << endl;
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cm.ShowProfit();
            sleep(2);
            system("cls");
            break;
        case 2:
            cm.ShowLoss();
            sleep(2);
            system("cls");
            break;
        case 0:
            choice = 0;
            break;
        default:
            cout << "\t";
            print_nchars_line(49, '-');
            cout << "\t|\t\tInvalid Option!!\t\t|" << endl;
            cout << "\t";
            print_nchars_line(49, '-');
            sleep(2);
            system("cls");
            break;
        }
    }
}


void showProductsCustomer()
{
    cm.displaySweets();
    system("pause");
    sleep(2);
    system("cls");

}

void makeOrderCustomer()
{
    int c=-1;
    while(c!=0)
    {
        int id;
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t|\t[1] Add order\t\t\t     |" << endl;
        cout << "\t\t\t|\t[2] Edit order\t\t\t     |" << endl;
        cout << "\t\t\t|\t[3] Delete order\t\t     |" << endl;
        cout << "\t\t\t|\t[4] List all orders\t\t     |" << endl;
        cout<<"\t\t\t|\t[5] ADD payment\t\t\t     |"<<endl;
        cout<<"\t\t\t|\t[6] display customer invoice\t     |"<<endl;
        cout << "\t\t\t|\t[0] Back to Previous menu\t     |" << endl;
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cm.addOrder();
            s6=neW;
            system("cls");
            break;
        case 2:
            cout << "__________________________________________________________________" << endl;
            cout << "|\t\tENTER ID OF THE ORDER TO EDIT: \t\t |" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << "\t\t\t\t ";
            cin >> id;
            cm.editOrder(id);
            s6=hold;
            sleep(2);
            system("cls");
            break;
        case 3:
            cout << "__________________________________________________________________" << endl;
            cout << "|\t\tENTER ID OF THE ORDER TO DELETE: \t\t |" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << "\t\t\t\t ";
            cin >> id;
            cm.deleteOrder(id);
            s6=canceled;
            sleep(2);
            system("cls");
            break;
        case 4:
            cm.displayOrders();
            sleep(2);
            system("cls");
            break;
        case 5:
            cout << "__________________________________________________________________" << endl;
            cout << "|\t\tENTER ID OF THE ORDER TO PAY : \t\t |" << endl;
            cout << "__________________________________________________________________" << endl;
            cout << "\t\t\t\t ";
            cin >> id;
            cm.addpayment(id);
            s6=paid;

            sleep(2);
            system("cls");
            break;
        case 6:
            cm.displayinvoice();
            switch(s6)
            {
            case 0:
                cout<<"STATUS|NEW";
                break;
            case 1:
                cout<<"STATUS|HOLD";
                break;
            case 2:
                cout<<"STATUS|PAID";
                break;
            case 3:
                cout<<"STATUS|CANCELED";
                break;

            }
            sleep(2);
            char choice;
            cout<<"\nBACK TO MAIN MANUE(y/n)?";
            cin>>choice;
            if(choice=='y')
            {
                system("cls");

                return;
            }

            break;


        case 0:
            return;
            break;


        }
    }
}

int main()
{
    welcome_screen(true);
    for (int i = 3; i >= 1; i--)
    {
        SetConsoleTextAttribute(h, 10);
        cout << "\n\n\n\t\t\t\t\tstarting app...";
        cout << i;
        sleep(1);
        system("cls");
        SetConsoleTextAttribute(h, 11);
    }

    int c = -1;
    int g;
    while (c != 0)
    {
        SetConsoleTextAttribute(h, 15);
        SetConsoleTextAttribute(h, 11);
        printline("\n\t\t\t******************************************************************");
        SetConsoleTextAttribute(h, 11);
        cout << "\t\t\t*\t\t\t\t\t\t\t\t *\n\t\t\t*\t\t\t";
        SetConsoleTextAttribute(h, 15);
        cout << " YOU ARE ?";
        SetConsoleTextAttribute(h, 11);
        cout << "\t\t\t\t *\n\t\t\t*\t\t\t\t\t\t\t\t *\n";

        printline("\t\t\t*\t\t\t 1-ADMIN\t\t\t\t *");
        printline("\t\t\t*\t\t\t 2-CUSTOMER\t\t\t         *");
        printline("\t\t\t*\t\t\t 0-EXIT\t\t\t\t\t *");
        printline("\t\t\t*\t\t\t\t\t\t\t\t *\n\t\t\t******************************************************************");
        cout << "\t\t\t>>SELECT A CHOICE: ";
        cin >> g;
        system("cls");
        switch (g)
        {
        case ADMIN:
        {
            int adminOption;
            while (true)
            {
                SetConsoleTextAttribute(h, 15);
                printline("\n\t\t\t\t\tADMIN MENU");
                SetConsoleTextAttribute(h, 11);
                printline("\n\t\t\t-------------------------------------------------");
                printline("\t\t\t|\t1- Customer Management\t\t\t  |");
                printline("\t\t\t|\t2- Sweets Management \t\t\t |");
                printline("\t\t\t|\t3- Show Profit and Loss\t\t\t |");
                printline("\t\t\t|\t0- Exit Admin\t\t\t\t |");
                printline("\t\t\t-------------------------------------------------");
                cout << "\t\t\t>>SELECT AN OPTION: ";
                cin >> adminOption;
                system("cls");

                switch (adminOption)
                {
                case CUSTOMER_MANAGEMENT:
                    customermanagement();
                    break;
                case PRODUCT_MANAGEMENT:
                    manageSweets();
                    break;
                case SHOW_PROFIT_AND_LOSS:
                    showProfitAndLossSubMenu();
                    break;
                case EXIT:
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    sleep(3);
                    system("cls");
                    break;
                }

                if (adminOption == EXIT)
                    break;
            }
            break;
        }
        case CUSTOMER:
        {
            int customerOption;
            while (true)
            {
                SetConsoleTextAttribute(h, 15);
                printline("\n\t\t\t\t\t*CUSTOMER MENU*");
                SetConsoleTextAttribute(h, 11);
                printline("\n\t\t\t-------------------------------------------------");
                printline("\t\t\t|\t1- Show Our Products\t\t\t|");
                printline("\t\t\t|\t2- Make Order\t\t\t\t|");
                printline("\t\t\t|\t0- Exit Customer\t\t\t|");
                printline("\t\t\t-------------------------------------------------");
                cout << "\t\t\t>>SELECT AN OPTION: ";
                cin >> customerOption;
                system("cls");

                switch (customerOption)
                {
                case SHOW_PRODUCTS_CUSTOMER:
                    cout << "\t\t\t       ) ( \n";
                    cout << "\t\t\t    ( ( ) ) \n";
                    cout << "\t\t\t     )   ( \n";
                    cout << "\t\t\t  (_________) \n";
                    cout << "\t\t\t   |       | \n";
                    cout << "\t\t\t   | Sweet | \n";
                    cout << "\t\t\t   |_______| \n";
                    showProductsCustomer();
                    sleep(2);
                    system("cls");
                    break;
                case MAKE_ORDER_CUSTOMER:
                    makeOrderCustomer();
                    break;
                case EXIT:
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    sleep(3);
                    system("cls");
                    break;
                }

                if (customerOption == EXIT)
                    break;
            }
            break;
        }
        case EXIT:
            c = 0;
            cout << endl << "\t\t";
            print_nchars_line(47, '-');
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t|      Thank You For Using Sweet Shop App     |\n";
            cout << "\t\t";
            SetConsoleTextAttribute(h, 11);
            print_nchars_line(47, '-');
            cout << "\t [Made By:Eng/ Tasneem Khaled, Rania Atef, Randa Adel, Rana Shehta]\n";
            break;
        default:
            cout << "\t";
            print_nchars_line(49, '-');
            cout << "\t|\t\tInvalid Option!!\t\t|" << endl;
            cout << "\t";
            print_nchars_line(49, '-');
            sleep(2);
            system("cls");
            break;
        }
    }
    return 0;
}
