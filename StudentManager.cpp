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
void StudentManager::searchStudent()
{
    int id;
    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (Student s : students)
    {
        if (s.id == id)
        {
            cout << "\nStudent Found\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void StudentManager::updateStudent()
{
    int id;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    for (Student &s : students)
    {
        if (s.id == id)
        {
            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Course: ";
            cin >> s.course;

            saveToFile();

            cout << "\nStudent Updated Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void StudentManager::deleteStudent()
{
    int id;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);

            saveToFile();

            cout << "\nStudent Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}
