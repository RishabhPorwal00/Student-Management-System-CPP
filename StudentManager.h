#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

using namespace std;

class StudentManager
{
private:
    vector<Student> students;

public:
    void addStudent();
    void viewStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();

    void loadFromFile();
    void saveToFile();
};

#endif
