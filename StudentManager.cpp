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
