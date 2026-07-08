#include <iostream>
#include "StudentManager.h"

using namespace std;

int main()
{
    StudentManager manager;
    manager.loadFromFile();

    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addStudent();
            break;

        case 2:
            manager.viewStudents();
            break;

        case 3:
            manager.searchStudent();
            break;

        case 4:
            manager.updateStudent();
            break;

        case 5:
            manager.deleteStudent();
            break;

        case 6:
            cout << "\nThank you for using Student Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
