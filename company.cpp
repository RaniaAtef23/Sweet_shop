#include "company.h"
#include<iostream>
using namespace std;
company::company()
{
                //ctor
}

company::~company()
{
                //dtor
}
void company::setdata(){
                customer::setdata();
                cout<<"location| ";
                cin>>location;
                cout<<"company_name";
                cin>>company_name;

}
void company::getdata(){

                customer::getdata();

cout<< "|\t location| "<<location<<"\tcompany_name|"<<company_name;
cout<<"\t\t\t|"<<endl;
                 cout<<"------------------------------------------------------------------\n";
}
 string company::gettype(){
                 return "company";
 }
 void company::setlocation(string newlocation){
                 location=newlocation;
 }
void company::setcompanyname(string newcompanyname){
                newcompanyname=company_name;
}
string company:: getlocation(){
                return location;
}
string company::getcompanyname(){
                return company_name;
}
company::company(int id,string name,string address,string location,string companyname){
                location=location;
                company_name=companyname;
}
