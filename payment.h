#ifndef PAYMENT_H
#define PAYMENT_H


class payment
{
                public:
                                payment();
                                virtual ~payment();
                                double pay;
                                virtual void set_info();
                                virtual void get_info();


                protected:

                private:
                                double amount;
};

#endif // PAYMENT_H
