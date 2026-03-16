#include<iostream>
using namespace std;

int stringLen(string str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

string stringCopy(string str)
{
    int i = 0;
    string cpy;

    while(str[i] != '\0')
    {
        cpy = cpy + str[i]; //concat
        i++;
    }
    return cpy;
}

int main()
{
    string str;
    cout<<"enter a string : ";
    cin>>str;

    int count = stringLen(str);
    cout<<"String Length = "<<count<<endl;

    cout<<"og string : "<<str<<endl;
    cout<<"copied string : "<<stringCopy(str)<<endl;

    return 0;

}