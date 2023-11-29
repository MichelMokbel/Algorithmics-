#include <iostream>
#include <fstream>
#include <String>

using namespace std;

struct course
{
    string name;
    int grade;
};

struct Student
{
    string firstname;
    string lastname;
    course c[2];
};

int main()
{

    Student s[3];
    s[0].firstname = "Tatiana";
    s[0].lastname = "Achkar";
    s[0].c[0].name = "P2";
    s[0].c[0].grade = 100;
    s[0].c[1].name = "DB";
    s[0].c[1].grade = 95;

    s[1].firstname = "Emilio";
    s[1].lastname = "Abou Nader";
    s[1].c[0].name = "P2";
    s[1].c[0].grade = 80;
    s[1].c[1].name = "DB";
    s[1].c[1].grade = 90;

    s[2].firstname = "Antoine";
    s[2].lastname = "Nassour";
    s[2].c[0].name = "P2";
    s[2].c[0].grade = 90;
    s[2].c[1].name = "DB";
    s[2].c[1].grade = 90;

    double avg1;
    double avg2;

    avg1 = (s[0].c[0].grade + s[1].c[0].grade + s[2].c[0].grade) / 3;
    avg2 = (s[0].c[1].grade + s[1].c[1].grade + s[2].c[1].grade) / 3;

    ofstream file;

    file.open("grades.txt", ios ::out);
    if (file.is_open())
    {

        file << "Course name : " <<  endl;
        // for (int i = 0; i < 3; i++)
        // {
        //     file << "First name : " << s[i].firstname << " Last name : " << s[i].lastname << " ";
        //     for (int j = 0; j < 2; j++)
        //     {
        //         file << "Course name : " << s[i].c[j].name << " Grade : " << s[i].c[j].grade << " ";
        //     }
        //     cout << endl;
        // }
        file.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    cout << "Course name : " << s[1].c[0].name << " Average grade " << avg1 << endl;
    cout << "Course name : " << s[1].c[1].name << " Average grade " << avg2 << endl;

    return 0;
}