#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void display(list<int> l2)
{
    cout << "l2 elements : ";
    list<int>::iterator l2itr = l2.begin();
    while (l2itr != l2.end())
    {
        cout << *l2itr << " , ";
        l2itr++;
    }
    cout << endl;
}

int main()
{
    //---------------enter date into list------------------

    list<int> l1;
    cout << "size : " << l1.size() << endl;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    l1.push_back(60);
    l1.push_back(70);
    l1.push_back(80);
    l1.push_back(90);
    l1.push_back(100);

    //------------------print list----------------------------

    cout << "size : " << l1.size() << endl;

    cout << "List : ";
    list<int>::iterator itr = l1.begin();
    while (itr != l1.end())
    {
        cout << *itr << " , ";
        itr++;
    }

    cout << endl;
    //---------------------reverse list --------------------------------
    cout << "reverse_list : ";
    list<int>::reverse_iterator itr3 = l1.rbegin();
    while (itr3 != l1.rend())
    {
        cout << *itr3 << " , ";
        itr3++;
    }

    cout << endl;
    // ----------------------Increment by 5 -----------------------------------
    itr = l1.begin();
    cout << "increment by 5 : ";
    while (itr != l1.end())
    {
        *itr += 5;
        cout << *itr << " , ";
        itr++;
    }
    //-----------------------Const Iterator-------------------------------------
    cout << endl;
    cout << "Const iterator list : ";
    list<int>::const_iterator citr = l1.cbegin();
    while (citr != l1.cend())
    {
        cout << *citr << " , ";
        citr++;
    }
    cout << endl;
    //-------------------------Sorting List using algorithms--------------------
    list<int> l2;
    l2.push_back(30);
    l2.push_back(10);
    l2.push_back(60);
    l2.push_back(5);
    l2.push_back(3);
    l2.push_back(70);

    display(l2);
    l2.sort();
    cout<<"sorted ";
    display(l2);
    //------------------------performing various operations on list-----------------
    l1.pop_front();
    l1.pop_back();

    cout << "List : ";
    itr = l1.begin();
    while (itr != l1.end())
    {
        cout << *itr << " , ";
        itr++;
    }

    l1.remove(30);
    l1.remove(40);
    cout << endl;

    cout << "List : ";
    list<int>::iterator itr2 = l1.begin();
    while (itr2 != l1.end())
    {
        cout << *itr2 << " , ";
        itr2++;
    }

    return 0;
}