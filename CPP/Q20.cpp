#include <iostream>
#include <memory>

using namespace std;

int main()
{
    //-----------Unique Pointer Ownership Transfer Demo-------------//
    cout<<"unique pointers : "<<endl;
    unique_ptr<int> p1 = make_unique<int>(50);

    cout << "value at p1 : " << *p1 << endl;

    // unique_ptr<int> p2 = p1;  // error

    unique_ptr<int> p2 = move(p1);
    cout << "value at p2 : " << *p2 << endl;
    if (p1 == nullptr)
    {
        cout << "p1 is empty";
    }
    cout << endl;

    //-----------shared ownership with shared_ptr-----------------------//

    cout << "Shared Pointer : " << endl;
    shared_ptr<int> s1 = make_shared<int>(20);
    {
        cout << "owners : " << s1.use_count() << endl;
        shared_ptr<int> s2 = s1;
        cout << "owners : " << s1.use_count() << endl;
    }

    //-------------non-owning reference with weak_ptr--------------------//
    
    cout<<"Weak poiter :"<<endl;
    weak_ptr<int> w1 = s1;

    if(auto shared = w1.lock())
    {
        cout<<"object value : "<<*shared<<endl;
    }
    else{
        cout<<"object has been destroyed";
    }
    return 0;
}
