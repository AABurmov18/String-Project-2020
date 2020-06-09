#include <iostream>
#include <string>
using namespace std;

struct ADMINISTRATOR
{
    string stUsername;
    string stPass;

    string trUsername;
    string trPass;
};

bool listDeleteAccountsmenu()
{
    cout << endl;                                    
    cout << "|==========================|" << endl;
    cout << "Choose which accounts you want to list : " << endl;
    cout << "1.Student accounts" << endl;
    cout << "2.Teacher accounts" << endl;
    cout << "3.Delete accounts" << endl;
    cout << "|==========================|" << endl;

retry4:

    int option5;
    cin >> option5;

    switch (option5)
    {
    case 1:
        //Function
        break;

    case 2:
        //Function
        break;

    case 3:
        //Function
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
}

void addTeacherAccounts(ADMINISTRATOR* reg, int trCounter) // Structura administrator -> 'reg'
{
    for (int i = 0; i < trCounter; i++)
    {
        cout << "Teacher Username: "; cin >> reg[i].trUsername;
        cout << "Teacher Pass: "; cin >> reg[i].trPass;
    }
    trCounter++;

    //generate id
}

void addStudentAccounts(ADMINISTRATOR* reg, int stCounter) // Structura administrator -> 'reg'
{
    for (int i = 0; i < stCounter; i++)
    {
        cout << "Student Username: "; cin >> reg[i].stUsername;
        cout << "Student Pass: "; cin >> reg[i].stPass;
    }
    stCounter++;

    //generate id
}

bool administratorMenu(ADMINISTRATOR* reg, int stCounter, int trCounter)
{
    cout << endl;                                    
    cout << "|==========================|" << endl;
    cout << "Welcome, administrator !" << endl;
    cout << "Choose option: " << endl;
    cout << "1. Add Student accounts" << endl;
    cout << "2. Add Teacher accounts" << endl;
    cout << "3. List & Delete accounts" << endl;
    cout << "|==========================|" << endl;

retry4:

    int option4;
    cin >> option4;

    switch (option4)
    {
    case 1:
        addStudentAccounts(reg, stCounter);
        break;

    case 2:
        addTeacherAccounts(reg, trCounter);
        break;

    case 3:
        listDeleteAccountsmenu();
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
}

bool checkSystemAdministrator(string adminPass, string adminpasstry, ADMINISTRATOR* reg, int stCounter, int trCounter)
{
retry4:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid password to access the administrator Menu !" << endl;
    cout << "Pass: "; getline(cin, adminpasstry); // da se dobavi '*'
    cout << "|============================================================================|" << endl;

    if (adminpasstry == adminPass)
    {
           administratorMenu(reg, stCounter, trCounter);
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry4;
    }
}

// ---------------------------------------------------------------------------- Student ----------------------------------------------------------------------------

bool studentMenu()
{
    cout << endl;                                     // Da se napravi structura Topic ! Vsqka shte si ima svoi unikalen kod (counter)
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. " << endl;
    cout << "2. See Topics" << endl;
    cout << "3. Edit Topic" << endl;
    cout << "4. Delete Topic" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option3;
    cin >> option3;

    switch (option3)
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

bool checkSystemStudent(string stUsername, string stpasstry)
{
retry2:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid username and password to access the student Menu !" << endl;
    cout << "Username: "; getline(cin, stUsername);
    cout << "Pass: "; getline(cin, stpasstry);
    cout << "|============================================================================|" << endl;

    if (// kato dobavim data -> tam shte ima zapisani deca (parola i ime) v tozi if shte proverim dali suotvetstvat)
    {
        teacherMenu();
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry2;
    }
}


// ---------------------------------------------------------------------------- Teacher ----------------------------------------------------------------------------


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

    int option2;
    cin >> option2;

    switch (option2)
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

bool checkSystemTeacher(string trPasstry, string trPassword)
{
retry2:
    cout << endl;
    cout << "|==================================================================|" << endl;
    cout << "You must enter a valid password to access the Teacher Menu !" << endl;
    cout << "Pass: "; getline(cin, trPasstry);                                                    // Da se dobavi '*' !
    cout << "|==================================================================|" << endl;

    if (trPasstry == trPassword)
    {
        teacherMenu();
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry2;
    }
}

bool mainMenu(string trPasstry, string trPassword, string stUsername, string stpasstry, string adminPass, string adminpasstry, ADMINISTRATOR* reg, int stCounter, int trCounter)
{
    cout << endl;
    cout << "|======================|" << endl;
    cout << "Choose your character" << endl;
    cout << "1. Teacher" << endl;
    cout << "2. Student" << endl;
    cout << "3. Administrator" << endl;
    cout << "|======================|" << endl;

retry1:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        checkSystemTeacher(trPasstry, trPassword);
        break;

    case 2:
        checkSystemStudent(stUsername, stpasstry);
        break;

    case 3:
        checkSystemAdministrator(adminPass, adminpasstry, reg, stCounter, trCounter);
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
}

int main()
{
    string trPassword = "english123";
    string trPasstry = "";
    int trCounter = 0;

    string stUsername = "";
    string stpasstry = "";
    int stCounter = 0;

    string adminPass = "adminadmin";
    string adminpasstry = "";
}