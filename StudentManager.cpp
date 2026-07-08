#include "StudentManager.h"
#include <fstream>

void StudentManager::loadFromFile()
{
    students.clear();
    ifstream file("students.txt");

    if (!file)
        return;

    Student s;

    while (file >> s.id >> s.name >> s.age >> s.course)
    {
        students.push_back(s);
    }

    file.close();
}

void StudentManager::saveToFile()
{
    ofstream file("students.txt");

    for (Student s : students)
    {
        file << s.id << " "
             << s.name << " "
             << s.age << " "
             << s.course << endl;
    }

    file.close();
}
void StudentManager::addStudent()
{
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Course: ";
    cin >> s.course;

    students.push_back(s);

    saveToFile();

    cout << "\nStudent Added Successfully!\n";
}

void StudentManager::viewStudents()
{
    if (students.empty())
    {
        cout << "\nNo Students Found!\n";
        return;
    }

    cout << "\n------ Student List ------\n";

    for (Student s : students)
    {
        cout << "ID: " << s.id << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course: " << s.course << endl;
        cout << "--------------------------\n";
    }
}
