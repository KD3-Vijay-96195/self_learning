#include<iostream>
using namespace std;

inline int factorial(int a)
{
    int result = 1;
    for(int i = a; i >= 1; i--)
        result = result * i;

    return result;
}

inline int power(int base, int index)
{
    int result = 1;

    for(int i = 1; i <= index; i++)
        result = result * base;

    return result;
}

int main()
{
    int fac = factorial(5);
    cout<<"Factorial = "<<fac<<endl;

    int pow = power(5,2);
    cout<<"Power : "<<pow<<endl;

    return 0;

}