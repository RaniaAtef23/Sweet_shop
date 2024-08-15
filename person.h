#ifndef PERSON_H
#define PERSON_H
#include"customer.h"

class person:public customer
{
public:
    person();
    virtual ~person();
    void getdata();
    void setdata();
    string gettype();
    void setbillig_address(string newbillingaddress);
    string getbillingaddress();
    void setfullname(string newfullname);
    string getfullname();
    person(int id,string name,string address,string fullname,string billing_address);


protected:
    string fullname;
    string billing_address;

private:
};

#endif // PERSON_H
