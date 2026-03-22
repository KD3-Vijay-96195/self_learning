#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student() { cout << "Student created" << endl; }
    ~Student() { cout << "Student destroyed" << endl; }
    void display() { cout << "Displaying student info..." << endl; }
};

template <typename T>
class SmartPtr
{
private:
    T* ptr;
public:

    explicit SmartPtr(T* p = nullptr) : ptr(p) {}

    ~SmartPtr()
    {
        delete ptr;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;
};

int main()
{
    try
    {
        SmartPtr<Student> s(new Student);

        throw runtime_error("Error during input");

        s->display(); 
    }
    catch (...)
    {
        cout << "Caught: Invalid input" << endl;
    }

    return 0;
}
