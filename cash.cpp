#include "cash.h"
#include<iostream>
using namespace std;
cash::cash()
{
                //ctor
}

cash::~cash()
{
                //dtor
}
void cash::set_info(){
                cout<<"enter cash value";
                cin>>cashvalue;
}
void cash::get_info(){
                cout<<"cashvalue| "<<cashvalue<<endl;
}
