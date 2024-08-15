#ifndef CASH_H
#define CASH_H

#include"payment.h"
class cash:public payment
{
                public:
                                cash();
                                virtual ~cash();
                                void set_info();
                                void get_info();


                protected:

                private:
                                double cashvalue;
};

#endif // CASH_H
