#include<iostream>
using namespace std;

class Payment{
    public:
   virtual void pay(int amount)=0;
   virtual ~Payment() = default;
};

class UPI:public Payment{
    public:
    void pay(int amount) override {
        cout<<amount<<" is pay through UPI";
    }
};
class DebitCard:public Payment{
    public:
    void pay(int amount) override {
        cout<<amount<<" is pay through DebitCard";
    }
};
class CreditCard:public Payment{
    public:
    void pay(int amount) override {
        cout<<amount<<" is pay through CreditCard";
    }
};
class QR:public Payment{
    public:
    void pay(int amount) override {
        cout<<amount<<" is pay through QR";
    }
};

class PaymentService{
    Payment *p;
    public:
    PaymentService(Payment *p){
        this->p=p;
    }

    void processPayment(int amount){
        p->pay(amount);
    }

};
int main(){
    Payment *p= new QR();
    PaymentService *strategy = new PaymentService(p);
    strategy->processPayment(300);
}
