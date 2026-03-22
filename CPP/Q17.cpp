#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student
{
private:
    int rollNo;
    char name[50];
    double marks;

public:
    Student() : rollNo(0), marks(0.0) { strcpy(name, ""); }
    
    Student(int r, const char* n, double m) : rollNo(r), marks(m)
    {
        strncpy(name, n, 49);
        name[49] = '\0';
    }

    void display()
    {
        cout << "Roll No: " << rollNo << " | Name: " << name << " | Marks: " << marks << endl;
    }

    // Save object to file
    void saveToFile(const string& filename)
    {
        ofstream outFile(filename, ios::binary | ios::app);
        if (outFile)
        {
            outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
            outFile.close();
            cout << "Data saved successfully." << endl;
        }
    }

    // Load object from file
    bool loadFromFile(const string& filename, int recordIndex = 0)
    {
        ifstream inFile(filename, ios::binary);
        if (inFile)
        {
            inFile.seekg(recordIndex * sizeof(*this)); // Move to specific record
            inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
            inFile.close();
            return true;
        }
        return false;
    }
};

int main()
{
    string file = "students.dat";

    // 1. Create and Save
    Student s1(101, "Alice Smith", 92.5);
    s1.saveToFile(file);

    // 2. Load and Display
    Student s2;
    if (s2.loadFromFile(file))
    {
        cout << "Loaded Data: ";
        s2.display();
    }

    return 0;
}
