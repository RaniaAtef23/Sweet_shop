#ifndef CREDIT_H
#define CREDIT_H
#include"payment.h"
#include<string>
using namespace std;
class credit:public payment
{
                public:
                                credit();
                                virtual ~credit();
                                void set_info();
                                void get_info();

                protected:

                private:
                                string number;
                                string type;
};

#endif // CREDIT_H
