#ifndef COMPANY_H
#define COMPANY_H
#include "customer.h"
#include<string>
class company:public customer
{
public:
    company();
    virtual ~company();
    void getdata();
    void setdata();
string gettype();
void setlocation(string newlocation);
void setcompanyname(string newcompanyname);
string getlocation();
string getcompanyname();
company(int id,string name,string address,string location,string companyname);
protected:
    string location;
    string company_name;


private:
};

#endif // COMPANY_H
