#include<iostream>
using namespace std;

void swap1(int &a, int &b) //reference swap
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) //pointer
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int a, int b) //by value
{
    int temp = a;
    a = b; 
    b = temp;

    cout<<"After swap by value"<<endl;
    cout<<a<<" "<<b<<endl;
}

int main()
{
    int m = 10;
    int n = 20;

    cout<<"Before swap by reference"<<endl;
    cout<<"m : "<<m<<" "<<"n : "<<n<<endl;
    swap1(m, n);
    cout<<"After swap by reference"<<endl;
    cout<<"m : "<<m<<" "<<"n : "<<n<<endl;

    cout<<"before swap by pointer"<<endl;
    cout<<"m : "<<m<<" "<<"n : "<<n<<endl;
    swap2(&m, &n);
    cout<<"After swap by pointer"<<endl;
    cout<<"m : "<<m<<" "<<"n : "<<n<<endl;

    cout<<"before swap by value"<<endl;
    cout<<"m : "<<m<<" "<<"n : "<<n<<endl;
    swap3(m,n);

    return 0;
}