#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string course;

    Student() {}

    Student(int i, string n, int a, string c)
    {
        id = i;
        name = n;
        age = a;
        course = c;
    }
};

#endif
