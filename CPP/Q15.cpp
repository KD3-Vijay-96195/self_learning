#include<iostream>
using namespace std;

class NegativeMarksException
{
    private:
    string message;

    public:
    NegativeMarksException(string message) : message(message)
    {   }

    string getMessage(void)
    {
        return this->message;
    }
    
};

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

        int getStudentId(void)
        {
            return this->id;
        }

        void setMarks(double marks)
        {
            if(marks < 0)
                throw NegativeMarksException("Negative Marks Not allowed");
            this->marks = marks;
        }

        void displayMarks(void)
        {
            cout<<this->marks;
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

        int getTeacherId(void)
        {
            return this->id;
        }

        void setSalary(double salary)
        {
            this->salary = salary;
        }

    };

};

int main()
{
    using namespace college;
    Student s1;
    try
    {
        s1.setMarks(-10);
        s1.displayMarks();
    }
    catch(NegativeMarksException ex)
    {
        cout<<ex.getMessage();
    }
    
};
