#include "person.h"
#include<iostream>
#include<fstream>
using namespace std;
person::person()
{
    //ctor
}

person::~person()
{
    //dtor
}
person::person(int id,string name,string address,string fullname,string billing_address){

                fullname=fullname;
                billing_address=billing_address;
}
void person::getdata()
{

    customer::getdata();
    cout<<"|\tfullname| "<<fullname<<"\tbilling_address| "<<billing_address<<"\t|"<<endl;
    cout<<"------------------------------------------------------------------\n";

}
void person::setdata()
{
    customer::setdata();
    cout<<"fullname";
    cin.ignore();
    getline(cin,fullname);

    cout<<"billing_address";
    cin>>billing_address;

}
 string person::gettype(){
                 return "person";
 }
  void person::setbillig_address(string newbillingaddress){
                  billing_address=newbillingaddress;
  }
    string person::getbillingaddress(){
                    return billing_address;
    }
    void person::setfullname(string newfullname){
                    fullname=newfullname;
    }
    string person::getfullname(){
                    return fullname;
    }
