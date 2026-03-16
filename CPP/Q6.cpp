#include<iostream>
using namespace std;

class BankAccount
{
    private:
    int accNum;
    string accName;
    double balance;

    public:
    BankAccount(void) : accNum(0), accName(""), balance(0.0)
    {   }
    BankAccount(int accNum, string accName, double balance) : accNum(accNum), accName(accName), balance(balance)
    {   }


    int getAccNum(void)
    {
        return this->accNum;
    }

    void setAccNum(int acNum)
    {
        this->accNum = acNum;
    }

    string getAccName(void)
    {
        return this->accName;
    }

    void setAccName(string acName)
    {
        this->accName = acName;
    }

    void addBalance(int amt)
    {
        this->balance +=  amt;
    }

    void subtractBalance(int amt)
    {
        if((this->balance-amt) >= 0)
        {
            this->balance -=  amt;
        }
        else
        {
            cout<<"insufficient balance"<<endl;
        }
    }

    double getBalance(void)
    {
        return this->balance;
    }


    static void acceptRecords(BankAccount B[], int count)
    {
        for(int i = 0; i<count; i++)
        {
            int acNum;
            string acName;
            cout<<"account number : ";
            cin>>acNum;
            B[i].setAccNum(acNum);
            
            cout<<"account Holder name : ";
            cin>>acName;
            B[i].setAccName(acName);

        }
    }


    static void deposit(BankAccount B[], int count)
    {
        int acNum;
        cout<<"enter account number : ";
        cin>>acNum;
        for(int i=0; i<count; i++)
        {
            if(B[i].getAccNum() == acNum)
            {
                double amt;
                cout<<"enter deposit ammount : ";
                cin>>amt;
                B[i].addBalance(amt);
            }
        }
       
    }

    static void withdraw(BankAccount B[], int count)
    {
        int acNum;
        cout<<"enter account number : ";
        cin>>acNum;
        for(int i = 0; i<count; i++)
        {
            if(B[i].getAccNum() == acNum)
            {
                double amt;
                cout<<"enter amount to withdramw : ";
                cin>>amt;
                B[i].subtractBalance(amt);
            }

        }
        
    }

    static double displayBalance(BankAccount B[], int count)
    {
        int acNum;
        cout<<"enter account number : ";
        cin>>acNum;
        double balance;
        for(int i = 0; i<count; i++)
        {
            if(B[i].getAccNum() == acNum)
            {
                balance = B[i].getBalance();  
            }

        }
        return balance;
    }


    static void displayRecord(BankAccount B[], int count)
    {
        for(int i=0; i<count; i++)
        {
            cout<<"accNum : "<<B[i].getAccNum()<<endl;
            cout<<"accName: "<<B[i].getAccName()<<endl;
            cout<<"balance : "<<B[i].getBalance()<<endl;
            cout<<endl;
        }
        
    }
};

int menuList(void)
{
    int choice;
    cout<<"\n 0. Exit \n 1. Accept Records \n 2. Deposit Amount \n 3. Withdraw Amount \n 4. Display Balance \n 5. Display Records \n";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int count;
    cout<<"enter no. of accounts to create : ";
    cin>>count;
    BankAccount *B = new BankAccount[count];

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                BankAccount::acceptRecords(B, count);
                break;
            }
            case 2:
            {
                BankAccount::deposit(B, count);
                break;
            }
            case 3:
            {
                BankAccount::withdraw(B, count);
                break;
            }
            case 4:
            {
                int bal;
                bal = BankAccount::displayBalance(B, count);
                cout<<bal;
                break;
            }
            case 5:
            {
                BankAccount::displayRecord(B, count);
                break;
            }
        }
    }
    return 0;
}
