#include <iostream>
using namespace std;

struct Student
{
    string roll;
    string name;
    float marks;
};

Student s[100];
int countStudent = 0;

void addStudent()
{
    cout << "\nEnter Roll Number: ";
    cin >> s[countStudent].roll;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s[countStudent].name);

    cout << "Enter Marks: ";
    cin >> s[countStudent].marks;

    countStudent++;

    cout << "Student Added Successfully!\n";
}

void displayStudents()
{
    if(countStudent == 0)
    {
        cout << "No records available.\n";
        return;
    }

    cout << "\nStudent Records\n";

    for(int i = 0; i < countStudent; i++)
    {
        cout << "Roll: " << s[i].roll << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Marks: " << s[i].marks << endl;
        cout << "---------------------\n";
    }
}

void searchStudent()
{
    string roll;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for(int i = 0; i < countStudent; i++)
    {
        if(s[i].roll == roll)
        {
            cout << "\nStudent Found\n";
            cout << "Roll: " << s[i].roll << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Marks: " << s[i].marks << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Student not found.\n";
    }
}

void deleteStudent()
{
    string roll;
    bool found = false;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for(int i = 0; i < countStudent; i++)
    {
        if(s[i].roll == roll)
        {
            for(int j = i; j < countStudent-1; j++)
            {
                s[j] = s[j+1];
            }

            countStudent--;

            cout << "Student Deleted Successfully!\n";
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Student not found.\n";
    }
}

void updateMarks()
{
    string roll;
    bool found = false;

    cout << "Enter Roll Number to update marks: ";
    cin >> roll;

    for(int i = 0; i < countStudent; i++)
    {
        if(s[i].roll == roll)
        {
            cout << "Enter New Marks: ";
            cin >> s[i].marks;

            cout << "Marks Updated Successfully!\n";
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Student not found.\n";
    }
}

void sortStudents()
{
    if(countStudent == 0)
    {
        cout << "No records available.\n";
        return;
    }

    for(int i = 0; i < countStudent-1; i++)
    {
        for(int j = i+1; j < countStudent; j++)
        {
            if(s[i].marks < s[j].marks)
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    cout << "Students sorted by marks (highest to lowest).\n";
}

void findTopper()
{
    if(countStudent == 0)
    {
        cout << "No records available.\n";
        return;
    }

    int top = 0;

    for(int i = 1; i < countStudent; i++)
    {
        if(s[i].marks > s[top].marks)
        {
            top = i;
        }
    }

    cout << "\nTopper Details\n";
    cout << "Roll: " << s[top].roll << endl;
    cout << "Name: " << s[top].name << endl;
    cout << "Marks: " << s[top].marks << endl;
}

void averageMarks()
{
    if(countStudent == 0)
    {
        cout << "No records available.\n";
        return;
    }

    float sum = 0;

    for(int i = 0; i < countStudent; i++)
    {
        sum += s[i].marks;
    }

    cout << "Average Marks: " << sum / countStudent << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Marks\n";
        cout << "6. Sort Students by Marks\n";
        cout << "7. Find Topper\n";
        cout << "8. Average Marks\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateMarks(); break;
            case 6: sortStudents(); break;
            case 7: findTopper(); break;
            case 8: averageMarks(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while(choice != 9);

    return 0;
}