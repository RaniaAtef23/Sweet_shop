#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iomanip>

#include<string>
using namespace std;
class customer
{
public:
    customer();
    virtual ~customer();
    virtual void setdata();
    virtual void getdata();
    int getuserid();
    void setuserid(int nid);
    void setname(const string& newName);
    string getname() const;


protected:
    string name;
    int id;
    string address;

private:
};

#endif // CUSTOMER_H
