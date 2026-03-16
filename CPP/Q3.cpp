#include<iostream>
using namespace std;

class Student
{
    private:
    int rollNo;
    double marks;

    public:
    Student(void) : rollNo(0), marks(0.0)
    {   }
    Student(int rollNo, double marks) : rollNo(rollNo), marks(marks)
    {   }

    void acceptRecord(void)
    {
        cout<<"roll No : ";
        cin>>this->rollNo;
        cout<<"marks : ";
        cin>>this->marks;
        cout<<endl;
    }

    void displayRecord(void)
    {
        cout<<"roll No : "<<this->rollNo<<endl;
        cout<<"marks : "<<this->marks<<endl;
        cout<<endl;
    }

    double getMarks(void)
    {
        return this->marks;
    }

    static double maxMarks(Student s[], int count)
    {
        double max = s[0].getMarks();

        for(int i=0; i<count; i++)
        {
            if(max < s[i].getMarks())
            {
                max = s[i].getMarks();
            }
        }
        return max;
    }

    static void topStudent(Student s[], int count)
    {
        double max = Student::maxMarks(s,count);
        for(int i = 0; i<count; i++)
        {
            if(s[i].getMarks() == max)
            {
                s[i].displayRecord();
            }
        }
        
    }
};

int menuList(void)
{
    int choice;
    cout<<"\n 0. exit \n 1. Enter records \n 2. Display Records \n 3. Calculate highest marks \n 4. Top Student \n ";
    cin>>choice;
    return choice;
}

int main()
{
    int count;
    int choice;
    cout<<"enter the no of records to enter: ";
    cin>>count;
    Student *s = new Student[count];

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                for(int i=0; i<count; i++)
                {
                    s[i].acceptRecord();
                }
                break;
            }

            case 2:
            {
                for(int i = 0; i<count; i++)
                {
                    s[i].displayRecord();
                }
                break;
            }
            case 3:
            {
                cout<<"max Marks = "<<Student::maxMarks(s,count)<<endl;
                break;
            }
            case 4:
            {
                cout<<"Topper Student: "<<endl;
                Student::topStudent(s,count);
                break;
            }
            
        }
    }

    delete[] s;
    s = NULL;
    return 0;
}