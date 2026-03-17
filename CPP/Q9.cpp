#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
        : name(n), age(a)
    {
        cout << "Person constructor called" << endl;
    }

    virtual void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Pure virtual function makes Person abstract
    virtual void work() = 0;
};

// Derived class Student
class Student : public Person
{
    int marks;

public:
    Student(string n, int a, int m)
        : Person(n, a), marks(m)
    {
        cout << "Student constructor called" << endl;
    }

    void display() override
    {
        Person::display();
        cout << "Marks: " << marks << endl;
    }

    void study()
    {
        cout << name << " is studying hard." << endl;
    }

    void work() override
    {
        cout << name << " works by studying and completing assignments." << endl;
    }
};

// Derived class Teacher
class Teacher : public Person
{
    double salary;

public:
    Teacher(string n, int a, double s)
        : Person(n, a), salary(s)
    {
        cout << "Teacher constructor called" << endl;
    }

    void display() override
    {
        Person::display();
        cout << "Salary: " << salary << endl;
    }

    void teach()
    {
        cout << name << " is teaching students." << endl;
    }

    void work() override
    {
        cout << name << " works by teaching and guiding students." << endl;
    }
};

int main()
{
    // Demonstrating runtime polymorphism
    Person* p1 = new Student("Alice", 20, 85);
    Person* p2 = new Teacher("Bob", 40, 50000);

    cout << "\n Student Details : " << endl;
    p1->display();
    p1->work();   // Calls Student's work()

    cout << "\n Teacher Details : " << endl;
    p2->display();
    p2->work();   // Calls Teacher's work()

    // Accessing derived-specific functions
    cout << "\n Derived Specific Functions : " << endl;
    dynamic_cast<Student*>(p1)->study();
    dynamic_cast<Teacher*>(p2)->teach();

    delete p1;
    delete p2;

    return 0;
}