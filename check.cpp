#include "check.h"
#include<iostream>
using namespace std;
check::check()
{
                //ctor
}

check::~check()
{
                //dtor
}
void check::set_info(){
                cout<<"enter your name";
                cin>>name;
                cout<<"enter bank-id";
                cin>>bank_id;
}
void check::get_info(){
                cout<<"NAME IS| "<<name<<"\tBANK-ID IS|"<<bank_id<<endl;
}
