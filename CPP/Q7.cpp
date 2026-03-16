#include<iostream>
using namespace std;

namespace college
{
    class Student
    {
        private:
        int id;
        string name;
        double marks;

        public:
        Student(void) : id(0), name(""), marks(0.0)
        {   }
        Student(int id, string name, double marks) : id(id), name(name), marks(marks)
        {   }

        void acceptRecord(void)
        {
            cout<<"id : ";
            cin>>this->id;
            cout<<"name : ";
            cin>>this->name;
            cout<<"marks : ";
            cin>>this->marks;
        }

        int getId(void)
        {
            return this->id;
        }

        void setMarks(double marks)
        {
            this->marks = marks;
        }

        void displayRecord(void)
        {
            cout<<"id : "<<this->id<<endl;
            cout<<"name : "<<this->name<<endl;
            cout<<"marks : "<<this->marks<<endl;
        } 
    };

    class Teacher
    {
        private:
        int id;
        string name;
        double salary;

        public:
        Teacher(void) : id(0), name(""), salary(0.0)
        {   }
        Teacher(int id, string name, double salary) : id(id), name(name), salary(salary)
        {   }

        void acceptRecord(void)
        {
            cout<<"id : ";
            cin>>this->id;
            cout<<"name : ";
            cin>>this->name;
            cout<<"salary : ";
            cin>>this->salary;
        }

        int getId(void)
        {
            return this->id;
        }

        void setSalary(double salary)
        {
            this->salary = salary;
        }

        void displayRecord(void)
        {
            cout<<"id : "<<this->id<<endl;
            cout<<"name : "<<this->name<<endl;
            cout<<"salary : "<<this->salary<<endl;
        }

    };
};

int main()
{
    using namespace college;

    Student s1;
    s1.acceptRecord();
    s1.displayRecord();
    s1.setMarks(200.0);
    s1.getId();
    s1.displayRecord();

    Teacher t1;
    t1.acceptRecord();
    t1.displayRecord();
    t1.setSalary(2000.0);
    t1.getId();
    t1.displayRecord();

    return 0;
    
}