#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Payment
{
protected:
    double amount;

public:
    Payment(double amt) : amount(amt) 
    {
    }

    virtual void makePayment() = 0; // Pure virtual function
    
    virtual ~Payment() 
    {
    }
};

class CreditCard : public Payment
{
    string cardNumber;

public:
    CreditCard(double amt, string card) : Payment(amt), cardNumber(card) 
    {
    }

    void makePayment() override
    {
        cout << "[Credit Card] Processing $" << amount 
             << " using card: " << cardNumber << "..." << endl;
        cout << "Payment Successful!" << endl;
    }
};

class UPI : public Payment
{
    string upiId;

public:
    UPI(double amt, string id) : Payment(amt), upiId(id) 
    {
    }

    void makePayment() override
    {
        cout << "[UPI] Initiating transaction of $" << amount 
             << " for VPA: " << upiId << "..." << endl;
        cout << "UPI Payment Authorized!" << endl;
    }
};

class Cash : public Payment
{
public:
    Cash(double amt) : Payment(amt) 
    {
    }

    void makePayment() override
    {
        cout << "[Cash] Payment of $" << amount 
             << " received in hand." << endl;
        cout << "Transaction Closed." << endl;
    }
};

class PaymentFactory
{
public:
    static Payment* create(const char* mode, double amount)
    {
        if (strcasecmp(mode, "CreditCard") == 0)
        {
            return new CreditCard(amount, "XXXX-XXXX-XXXX-1234");
        }
        else if (strcasecmp(mode, "UPI") == 0)
        {
            return new UPI(amount, "user@okbank");
        }
        else if (strcasecmp(mode, "Cash") == 0)
        {
            return new Cash(amount);
        }
        
        return nullptr;
    }
};

int main()
{
    double amt;
    string mode;

    cout << "Enter payment amount: ";
    cin >> amt;
    cout << "Enter payment mode (CreditCard/UPI/Cash): ";
    cin >> mode;

    Payment* myPayment = PaymentFactory::create(mode.c_str(), amt);

    if (myPayment != nullptr)
    {
        myPayment->makePayment();
        delete myPayment;
    }
    else
    {
        cout << "Error: Invalid Payment Mode!" << endl;
    }

    return 0;
}
