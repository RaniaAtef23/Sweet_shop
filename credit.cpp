#include "credit.h"
#include<iostream>
using namespace std;
credit::credit()
{
                //ctor
}

credit::~credit()
{
                //dtor
}
void credit::set_info(){
                cout<<"enter your number| ";
                cin>>number;
                cout<<"enter type of credit| ";
                cin>>type;
}
void credit:: get_info(){
                cout<<"your number is| "<<number<<endl;
                cout<<"type of credit | "<<type<<endl;

}
