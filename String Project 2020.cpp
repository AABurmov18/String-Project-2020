#include <iostream>
#include <string>
using namespace std;

int idgenerator(int& maxId)
{
    maxId++;
    return maxId;
}

struct ADMINISTRATOR
{
    string stUsername;
    string stPass;

    string trUsername;
    string trPass;
};

struct QUIZ 
{
    string quizName;
    string quizQuestions;


    string answers;
};

// ---------------------------------------------------------------------------- Administrator ----------------------------------------------------------------------------

int findId(ADMINISTRATOR* reg, int trCounter, int& maxId, int stCounter, int searchID)
{
    cout << endl;
    cout << "|===============================|" << endl;
    cout << "Enter the account ID: "; cin >> searchID;
    cout << "|===============================|" << endl;
    for (int i = 0; i < stCounter; i++)
    {
        for (int i = 0; i < trCounter; i++)
        {
            if (searchID == maxId)
            {
                return i;
            }
        }
    }
}

void deleteAccount(ADMINISTRATOR* reg, int trCounter, int& maxId, int stCounter, int searchID)
{
    for (int i = findId(reg, stCounter, searchID, maxId, stCounter); i < stCounter - 1; i++)
    {
        for (int i = findId(reg, stCounter, searchID, maxId, stCounter); i < trCounter - 1; i++)
        {
            reg[i] = reg[i + 1];
        }
    }
    stCounter--;
    trCounter--;
}

void viewTeacherAccounts(ADMINISTRATOR* reg, int trCounter, int& maxId)
{
    for (int i = 0; i < trCounter; i++)
    {
        cout << endl;
        cout << "|===============================|" << endl;
        cout << "Teacher Username: "; cout << reg[i].trUsername;
        cout << "Teacher Pass: "; cout << reg[i].trPass;
        cout << "Account ID: "; cout << maxId;
        cout << "|===============================|" << endl;
    }
}

void viewStudentaccounts(ADMINISTRATOR* reg, int stCounter, int& maxId)
{
    for (int i = 0; i < stCounter; i++)
    {
        cout << endl;
        cout << "|===============================|" << endl;
        cout << "Student Username: "; cout << reg[i].stUsername;
        cout << "Student Pass: "; cout << reg[i].stPass;
        cout << "Account ID: "; cout << maxId;
        cout << "|===============================|" << endl;
    }
}

bool listDeleteAccountsMenu(ADMINISTRATOR* reg, int trCounter, int& maxId, int stCounter, int searchID)
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
        viewStudentaccounts(reg,stCounter,maxId);
        break;

    case 2:
        viewTeacherAccounts(reg,trCounter,maxId);
        break;

    case 3:
        deleteAccount(reg, trCounter, maxId, stCounter, searchID);
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
}

void addTeacherAccounts(ADMINISTRATOR* reg, int trCounter, int& maxId) // Structura administrator -> 'reg'
{
    for (int i = 0; i < trCounter; i++)
    {
        cout << endl;
        cout << "|==========================|" << endl;
        cout << "Teacher Username: "; cin >> reg[i].trUsername;
        cout << "Teacher Pass: "; cin >> reg[i].trPass;
        cout << "|==========================|" << endl;
    }
    trCounter++;

    idgenerator(maxId);
}

void addStudentAccounts(ADMINISTRATOR* reg, int stCounter, int& maxId) // Structura administrator -> 'reg'
{
    for (int i = 0; i < stCounter; i++)
    {
        cout << endl;
        cout << "|==========================|" << endl;
        cout << "Student Username: "; cin >> reg[i].stUsername;
        cout << "Student Pass: "; cin >> reg[i].stPass;
        cout << "|==========================|" << endl;
    }
    stCounter++;

    idgenerator(maxId);
}

bool administratorMenu(ADMINISTRATOR* reg, int stCounter, int trCounter, int& maxId,int searchID)
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
        addStudentAccounts(reg,stCounter,maxId);
        break;

    case 2:
        addTeacherAccounts(reg, trCounter, maxId);
        break;

    case 3:
        listDeleteAccountsMenu(reg, trCounter, maxId, stCounter, searchID);
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
}

bool checkSystemAdministrator(string adminPass, string adminpasstry, ADMINISTRATOR* reg, int stCounter, int trCounter, int& maxId, int searchID)
{
retry4:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid password to access the administrator Menu !" << endl;
    cout << "Pass: "; getline(cin, adminpasstry); // da se dobavi '*'
    cout << "|============================================================================|" << endl;

    if (adminpasstry == adminPass)
    {
        administratorMenu(reg, stCounter, trCounter, maxId, searchID);
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry4;
    }
}

// ---------------------------------------------------------------------------- Student ----------------------------------------------------------------------------
void Quiz(QUIZ* quiz, int quizcount, int& maxId, QUIZ* quizQuestions, int quiznumber, int& amount, QUIZ* studentAns)
{
    cout << "Welcome to" << quiz[quiznumber].quizzName << "Quiz!";
    for (int i = 0; i < quiz[quiznumber].amount)
    {
        cout << i + 1 << quiz[quiznumber].quizQuestions[i];
        cout << "\nType your answer here:";
        cin >> quiz[quiznumber].studentAns[i];
    }
    cout << "Quiz completed";
    cout << "Check your grades for any updates";
}
void chooseQuiz(QUIZ* quiz, int quizcount, int& maxId, int quiznumber, char YN)
{
    returnyn;
    for (int i = 0; i < quizcount; i++)
    {
        cout << "|================================================|" << endl;
        cout << "All Quizzes:"
            cout << i + 1 << ". " << quiz[i].quizName;


    }
    cout << "\n\nOn what quiz do you want to work on?"; cin >> quiznumber;
returninc:
    cout << "\nDo you wish to start now?(y|n)"; cin >> YN;
    if (YN == y)
    {
        startQuiz(quiznumber);
    }
    else if (YN == n)
    {
        goto returnyn;
    }
    else
    {
        cout << "Incorrect input";
        goto returninc;
    }
}

bool studentMenu()
{
    cout << endl;                                     // Da se napravi structura Quiz ! Vsqka shte si ima svoi unikalen kod (counter)
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. See Quizzes" << endl;
    cout << "2. Exit Student Menu" << endl;
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

bool checkSystemStudent(string stUsername, string stpasstry, QUIZ* quiz, int quizcount, int& maxId, int searchID)
{
retry10:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid username and password to access the student Menu !" << endl;
    cout << "Username: "; getline(cin, stUsername);
    cout << "Pass: "; getline(cin, stpasstry);
    cout << "|============================================================================|" << endl;
    if (stUsername != "" && stpasstry != "") // kato dobavim data -> tam shte ima zapisani deca (parola i ime) v tozi if shte proverim dali suotvetstvat
    {
        cout << "Congrats !";
        //studentMenu();
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry10;
    }
}


// ---------------------------------------------------------------------------- Teacher ----------------------------------------------------------------------------

int findIdQuiz(QUIZ* quiz, int quizcount, int& maxId, int searchID)
{
    cout << endl;
    cout << "|===============================|" << endl;
    cout << "Enter the quiz ID: "; cin >> searchID;
    cout << "|===============================|" << endl;
    for (int i = 0; i < quizcount; i++)
    {
        if (searchID == maxId)
        {
            return i;
        }
    }
}

void deleteQuiz(QUIZ* quiz, int quizcount, int& maxId, int searchID)
{
    for (int i = findIdQuiz(quiz,quizcount,maxId,searchID); i < quizcount - 1; i++)
    {
        quiz[i] = quiz[i + 1];
    }
    quizcount--;
}

void viewQuiz(QUIZ* quiz, int quizcount, int& maxId, int quiznumber)
{
    for (int i = 0; i < quizcount; i++)
    {
        cout << "|================================================|" << endl;
        cout << "All Quiz:";
        cout << i << ". " << quiz[i].quizName;

    }
    cout << "\n\nSelect a quiz, that you want to see tha questions of."; cin >> quiznumber;



    for (int i = 0; i < quizcount; i++)
    {
        cout << "Questions" << endl;
        cout << i << quiz[quiznumber].quizQuestions[i];
        cout << "Quiz ID: "; cout << maxId;
        cout << "|================================================|" << endl;
        cout << endl;
    }
}

void createQuiz(QUIZ* quiz, int quizcount, int& maxId)
{
    int amount;

    cout << endl;
    cout << "|==========================|" << endl;
    cout << "Enter the name of the Quiz"; getline(cin, quiz[quizcount].quizName);

retry7:
    cout << "Enter the amount of the questions"; cin >> amount; 
    if (amount > 0)
    {
        for (int i = 0; i < amount; i++)
        {
            cout << i << " "; getline(cin, quiz[quizcount].quizQuestions);
            cout << endl;
        }
        quizcount++;
        cout << "|==========================|" << endl;

        idgenerator(maxId);
    }
    else
    {
        cout << "Incorrect Input" << endl;
        goto retry7;
    }
}

bool teacherMenu(QUIZ* quiz, int quizcount, int& maxId, int searchID)
{
    cout << endl;
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. Create Quiz" << endl;
    cout << "2. View Quizzes" << endl;
    cout << "3. Delete Quiz" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option2;
    cin >> option2;

    switch (option2)
    {
    case 1:
        createQuiz(quiz, quizcount, maxId);
        break;

    case 2:
        viewQuiz(quiz, quizcount, maxId);
        break;

    case 3:
        deleteQuiz(quiz, quizcount, maxId, searchID);
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry3;
    }
}

bool checkSystemTeacher(string trPasstry, string trPassword, QUIZ* quiz, int quizcount, int& maxId, int searchID)
{
retry2:
    cout << endl;
    cout << "|==================================================================|" << endl;
    cout << "You must enter a valid password to access the Teacher Menu !" << endl;
    cout << "Pass: "; getline(cin, trPasstry);                                                    // Da se dobavi '*' !
    cout << "|==================================================================|" << endl;

    if (trPasstry == trPassword)
    {
        teacherMenu(quiz,quizcount,maxId,searchID);
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry2;
    }
}

bool mainMenu(string trPasstry, string trPassword, string stUsername, string stpasstry, string adminPass, string adminpasstry, ADMINISTRATOR* reg, int stCounter, int trCounter,int searchID, int& maxId, int quizcount, QUIZ* quiz)
{
    cout << endl;
    cout << "|======================|" << endl;
    cout << "Choose your character" << endl;
    cout << "1. Teacher" << endl; // In progress
    cout << "2. Student" << endl; // In progress
    cout << "3. Administrator" << endl; // Complete
    cout << "|======================|" << endl;

retry1:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        checkSystemTeacher(trPasstry, trPassword, quiz, quizcount, maxId, searchID);
        break;

    case 2:
        checkSystemStudent(stUsername, stpasstry, quiz,  quizcount, maxId, searchID);
        break;

    case 3:
        checkSystemAdministrator(adminPass, adminpasstry, reg, stCounter, trCounter, maxId, searchID);
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
}

int main()
{
    int quizcount = 0;

    //
    string trPassword = "english123";
    string trPasstry = "";
    int trCounter = 0;

    string stUsername = "";
    string stpasstry = "";
    int stCounter = 0;

    //
    string adminPass = "adminadmin";
    string adminpasstry = "";

    int maxId = 0;
    int searchID = 0;
}