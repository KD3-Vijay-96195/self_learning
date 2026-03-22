#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
private:
    T* data;
    int size;

public:

    Array(int s) : size(s)
    {
        data = new T[size];
    }

    ~Array()
    {
        delete[] data;
    }

    Array(const Array& other)
    {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Overload Subscript Operator (L-value and R-value access)
    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int getSize() const 
    { 
        return size; 
    }
};

class Student
{
public:
    string name;
    int roll;
    
    Student() : name(""), roll(0) {} 
    Student(string n, int r) : name(n), roll(r) {}

    void display() const
    {
        cout << "[" << roll << ": " << name << "] ";
    }
};

int main()
{
    try
    {
        Array<int> intArray(3);
        intArray[0] = 10;
        intArray[1] = 20;
        cout << "Integer Array: " << intArray[0] << ", " << intArray[1] << endl;

        Array<Student> studentList(2);
        studentList[0] = Student("Alice", 101);
        studentList[1] = Student("Bob", 102);

        cout << "Student Array: ";
        for (int i = 0; i < studentList.getSize(); i++)
        {
            studentList[i].display();
        }
        cout << endl;
    }
    catch (const exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
