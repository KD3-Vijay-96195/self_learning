#include <iostream>
using namespace std;

class Programmer
{
    string language;
    int experience;
    double salary;

public:
    Programmer(string lang = "C++", int exp = 2, double sal = 50000)
        : language(lang), experience(exp), salary(sal)
    {
        cout << "Programmer constructor called" << endl;
    }

    void work()
    {
        cout << "Programming in " << language
             << " with " << experience << " years experience." << endl;
    }
};

class Teacher
{
    string subject;
    int teachingExperience;
    double salary;

public:
    Teacher(string sub = "Computer Science", int exp = 5, double sal = 40000)
        : subject(sub), teachingExperience(exp), salary(sal)
    {
        cout << "Teacher constructor called" << endl;
    }

    void work()
    {
        cout << "Teaching " << subject
             << " with " << teachingExperience << " years experience." << endl;
    }
};

class ProgrammingTeacher : public Programmer, public Teacher
{
    string courseName;
    int batchSize;

public:
    ProgrammingTeacher(string cname = "C++ Basics", int bsize = 30)
        : Programmer("C++", 5, 60000),
          Teacher("Computer Science", 7, 50000),
          courseName(cname),
          batchSize(bsize)
    {
        cout << "ProgrammingTeacher constructor called" << endl;
    }

    void showDetails()
    {
        cout << "Course: " << courseName
             << ", Batch size: " << batchSize << endl;
    }
};

int main()
{
    ProgrammingTeacher pt;

    // Ambiguity: both Programmer and Teacher have work()
    // pt.work();   // Error: ambiguous

    // Resolving ambiguity using scope resolution
    pt.Programmer::work();
    pt.Teacher::work();

    pt.showDetails();

    return 0;
}