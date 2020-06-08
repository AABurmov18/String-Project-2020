#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct STUDENT
{
    string firstName = "";
    string lastName = "";

    char studentKlas;
    char studentNumber;

    string username = "ivan";
    string studentPass = "ivan123";
};

bool studentMenu()
{
    cout << endl;                                     // Da se napravi structura Topic ! Vsqka shte si ima svoi unikalen kod (counter)
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. Create Topic" << endl;
    cout << "2. See Topics" << endl;
    cout << "3. Edit Topic" << endl;
    cout << "4. Delete Topic" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        // Function
        break;

    case 2:
        // Function
        break;

    case 3:
        // Function
        break;

    case 4:
        // Function
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry3;
    }
}

bool checkSystemStudent(int studentCounter, STUDENT* username, STUDENT* studentPass)
{
retry2:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid username and password to access the student's Menu !" << endl;
    cout << "Username: "; getline(cin, [studentCounter].username)                                                 // za popravka ! Da pomislim nai-udachen variant
        cout << "Pass: ";  getline(cin, [studentCounter].studentPass)     // Da se dobavi '*' !
        cout << "|============================================================================|" << endl;

    if ([studentCounter].studentPass == password)
    {
        teacherMenu();
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry2;
    }
}

bool teacherMenu()
{
    cout << endl;                                     // Da se napravi structura Topic ! Vsqka shte si ima svoi unikalen kod (counter)
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. Create Topic" << endl;
    cout << "2. See Topics" << endl;
    cout << "3. Edit Topic" << endl;
    cout << "4. Delete Topic" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        // Function
        break;

    case 2:
        // Function
        break;

    case 3:
        // Function
        break;

    case 4:
        // Function
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry3;
    }
}

bool checkSystemTeacher(string passtry, string password)
{
retry2:
    cout << endl;
    cout << "|==================================================================|" << endl;
    cout << "You must enter a valid password to access the Teacher's Menu !" << endl;
    cout << "Pass: "; getline(cin, passtry);                                                    // Da se dobavi '*' !
    cout << "|==================================================================|" << endl;

    if (passtry == password)
    {
        teacherMenu();
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry2;
    }
}

bool mainMenu(string passtry, string password)
{
    cout << endl;
    cout << "|======================|" << endl;
    cout << "Choose your character" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cout << "|======================|" << endl;

retry1:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        checkSystemTeacher(passtry, password);
        break;

    case 2:
        studentMenu();
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
}

int main()
{
    string password = "english123";
    string passtry = "";

    int studentCounter = 0;
}