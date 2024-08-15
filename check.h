#ifndef CHECK_H
#define CHECK_H
#include<string>
#include"payment.h"
using namespace std;
class check:public payment
{
                public:
                                check();
                                virtual ~check();
                                void set_info();
                                void get_info();


                protected:

                private:
                                string name;
                                string bank_id;
};

#endif // CHECK_H
