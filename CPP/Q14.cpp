#include<iostream>
using namespace std;

class ExceptionMessage
{
    private:
    string invalidMessage;
    public:
    ExceptionMessage(string message)
    {   
        this->invalidMessage = message;
    }

    string getInvalidMessage(void)
    {
        return this->invalidMessage;
    }
};

class ExceptionAmount
{
    private:
    double invalidAmount;

    public:
    ExceptionAmount(double amount)
    {
        this->invalidAmount = amount;
    } 

    double getInvalidAmount(void)
    {
        return this->invalidAmount;
    }
};

class BankAccount
{
    private:
    int accNum;
    string accName;
    double balance;

    public:
    BankAccount() : accNum(0), accName(""), balance(0.0)
    {   }



    void deposit(double amt)
    {
        if(amt <= 0)
            throw ExceptionAmount(-1);

        this->balance += amt;
    }

    void withdraw(double amt)
    {
        if((this->balance - amt) <= 0)
            throw ExceptionMessage("Insufficient Balance");

        this->balance -= amt;
    }

    void displayBalance(void)
    {
        cout<<"balance : "<<this->balance<<endl;
    }
};

int main()
{
    BankAccount b1;
    try
    {
        b1.deposit(100);
        b1.withdraw(200);
        b1.displayBalance();
    }
    catch(ExceptionAmount ex)
    {
        cout<<ex.getInvalidAmount();
    }
    catch(ExceptionMessage em)
    {
        cout<<em.getInvalidMessage();
    }
    
    return 0;
}

