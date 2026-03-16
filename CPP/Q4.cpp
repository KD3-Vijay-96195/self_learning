#include<iostream>
using namespace std;

class Laptop
{
    private:
    int brandId;
    double price;

    public:
    Laptop(void) : brandId(1), price(5000)
    {
        cout<<"Laptop Constructor Called"<<endl;
    }
    Laptop(int brandId, double price) : brandId(brandId), price(price)
    {   }

    void acceptDetails(void)
    {
        cout<<"brand id : ";
        cin>>this->brandId;
        cout<<"price : ";
        cin>>this->price;
    }
    void displayDetails(void)
    {
        cout<<"brand id : "<<this->brandId<<endl;
        cout<<"price : "<<this->price<<endl;
    }


    ~Laptop()
    {
        cout<<"Laptop Destructor Called"<<endl;
    }

};

int main()
{
    Laptop L1;
    L1.displayDetails();
    cout<<"enter details :"<<endl;
    L1.acceptDetails();
    L1.displayDetails();

    return 0;
}