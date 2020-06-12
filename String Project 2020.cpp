#include <iostream>
#include <string>
using namespace std;

bool showMainMenu = true;

int idgenerator(int& maxId)
{
    maxId++;
    return maxId;
}

struct ADMINISTRATOR
{
    string stUsername;
    string stPass;

	string reg;

    string trUsername;
    string trPass;
};

struct QUIZ_QUESTION
{
    string title;
    string answer;

    string studentAnswer;
};

struct QUIZ
{
    string quizName;

    int questionCount;

	string quiz;

    QUIZ_QUESTION questions[100];
};


// ---------------------------------------------------------------------------- Administrator ----------------------------------------------------------------------------

int findIdst(ADMINISTRATOR* reg, int& maxId, int& stCounter, int searchID)
{
    cout << endl;
    cout << "|===============================|" << endl;
    cout << "Enter the account ID: "; cin >> searchID;
    cout << "|===============================|" << endl;
    for (int i = 0; i < stCounter; i++)
    {
        if (searchID == maxId)
        {
            return i;
        }
    }
}

int findIdtr(ADMINISTRATOR* reg, int& trCounter, int& maxId, int searchID)
{
    cout << endl;
    cout << "|===============================|" << endl;
    cout << "Enter the account ID: "; cin >> searchID;
    cout << "|===============================|" << endl;
    for (int i = 0; i < trCounter; i++)
    {
        if (searchID == maxId)
        {
            return i;
        }
    }
}

void deletetrAccount(ADMINISTRATOR* reg, int& trCounter, int& maxId, int searchID)
{
    for (int i = findIdtr(reg, searchID, maxId, trCounter); i < trCounter - 1; i++)
    {
        reg[i] = reg[i + 1];
    }
    trCounter--;
}

void deletestAccount(ADMINISTRATOR* reg, int& maxId, int& stCounter, int searchID)
{
    for (int i = findIdst(reg, searchID, maxId, stCounter); i < stCounter - 1; i++)
    {      
        reg[i] = reg[i + 1];       
    }
    stCounter--;
}

void viewTeacherAccounts(ADMINISTRATOR* reg, int trCounter, int& maxId)
{
    for (int i = 0; i < trCounter; i++)
    {
        cout << endl;
        cout << "|===============================|" << endl;
        cout << "Teacher Username: "; cout << reg[i].trUsername;
        cout << endl;
        cout << "Teacher Pass: "; cout << reg[i].trPass;
        cout << endl;
        cout << "Account ID: "; cout << maxId;
        cout << endl;
        cout << "|===============================|" << endl;
    }
}

void viewStudentaccounts(ADMINISTRATOR* reg, int stCounter, int& maxId)
{
    for (int i = 0; i < stCounter; i++)
    {
        cout << endl;
        cout << "|===============================|" << endl;
        cout << endl;
        cout << "Student Username: "; cout << reg[i].stUsername;
        cout << endl;
        cout << "Student Pass: "; cout << reg[i].stPass;
        cout << endl;
        cout << "Account ID: "; cout << maxId;
        cout << endl;
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
    cout << "3.Delete Student Account" << endl;
    cout << "3.Delete Teacher Account" << endl;
	cout << "4.Go back to main menu" << endl;
    cout << "|==========================|" << endl;

retry4:

    int option5;
    cin >> option5;

    switch (option5)
    {
    case 1:
        viewStudentaccounts(reg, stCounter, maxId);
        break;

    case 2:
        viewTeacherAccounts(reg, trCounter, maxId);
        break;

    case 3:
        deletestAccount(reg, maxId, stCounter, searchID);
        break;

    case 4:
        deletetrAccount(reg, trCounter, maxId, searchID);
        break;

	case 5:
		return false;
		break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
	return true;
}

void addTeacherAccounts(ADMINISTRATOR* reg, int& trCounter, int& maxId) // Structura administrator -> 'reg'
{
    int amount;
    cout << "Enter the amount of the accounts you want to add: "; cin >> amount;

    for (int i = 0; i < amount; i++)
    {
        cout << endl;
        cout << "|==========================|" << endl;
        cout << "Teacher Username: "; cin >> reg[trCounter].trUsername;
        cout << "Teacher Pass: "; cin >> reg[trCounter].trPass;
        cout << "|==========================|" << endl;
    }
    trCounter++;

    idgenerator(maxId);
}

void addStudentAccounts(ADMINISTRATOR* reg, int& stCounter, int& maxId) // Structura administrator -> 'reg'
{
    int amount;
    cout << "Enter the amount of the accounts you want to add: "; cin >> amount;

    for (int i = 0; i < amount; i++)
    {
        cout << endl;
        cout << "|==========================|" << endl;
        cout << "Student Username: "; cin >> reg[stCounter].stUsername;
        cout << "Student Pass: "; cin >> reg[stCounter].stPass;
        cout << "|==========================|" << endl;
    }
    stCounter++;

    idgenerator(maxId);
}

bool administratorMenu(ADMINISTRATOR* reg, int& stCounter, int& trCounter, int& maxId, int searchID)
{
    cout << endl;
    cout << "|==========================|" << endl;
    cout << "Welcome, administrator !" << endl;
    cout << "Choose option: " << endl;
    cout << "1. Add Student accounts" << endl;
    cout << "2. Add Teacher accounts" << endl;
    cout << "3. List & Delete accounts" << endl;
	cout << "4. Go back to main menu" << endl;
    cout << "|==========================|" << endl;

retry4:

    int option4;
    cin >> option4;

    switch (option4)
    {
    case 1:
        addStudentAccounts(reg, stCounter, maxId);
        break;

    case 2:
        addTeacherAccounts(reg, trCounter, maxId);
        break;

    case 3:
        listDeleteAccountsMenu(reg, trCounter, maxId, stCounter, searchID);
        break;

    case 4:
        return false;
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry4;
    }
	return true;
}

bool checkSystemAdministrator(string adminPass, string adminpasstry, ADMINISTRATOR* reg, int& stCounter, int& trCounter, int& maxId, int searchID)
{
retry4:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid password to access the administrator Menu !" << endl;
    cout << "Pass: "; cin >> adminpasstry;
    cout << "|============================================================================|" << endl;

    if (adminpasstry == adminPass)
    {
        administratorMenu(reg, stCounter, trCounter, maxId, searchID);
        return true;
    }
    else
    {
        cout << "Try Again !" << endl;
        goto retry4;
    }
}

// ---------------------------------------------------------------------------- Student ----------------------------------------------------------------------------


void viewQuizName(QUIZ* quiz, int& quizcount, int& maxId)
{
    for (int i = 0; i < quizcount; i++)
    {
        cout << endl;
        cout << "|================================================|" << endl;
        cout << "Quiz Name: " << quiz[i].quizName;
        cout << endl;
        cout << "Quiz ID: "; cout << maxId;
        cout << endl;
        cout << "|================================================|" << endl;
    }
}

int findIdQuiz(QUIZ* quiz, int& quizcount, int& maxId, int searchID)
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

void startQuiz(QUIZ* quiz, int& quizcount, int& maxId, int searchID, int& stanswercount, int& quizAnswercount)
{
    cin.ignore();
    int quizIndex = findIdQuiz(quiz, quizcount, maxId, searchID);

        cout << endl;
        cout << "|================================================|" << endl;
        cout << "Quiz Name: " << quiz[quizIndex].quizName;
        cout << endl;
        for (int j = 0; j < quiz[quizIndex].questionCount; j++)
        {
            cout << "[" << j << "]" << "Question: " << quiz[quizIndex].questions[j].title;
            cout << endl;
            cout << "Your Answer: "; getline(cin, quiz[quizIndex].questions[j].studentAnswer);
            cout << endl;
            stanswercount++;
        }
        cout << "|================================================|" << endl;

}

void checkStudentResult(QUIZ* quiz, int quizcount, int& maxId, int searchID, int stanswercount, int& AnswerCounterStudent)
{
    for (int i = 0; i < quizcount; i++)
    {
        for (int i = 0; i < stanswercount; i++)
        {
            if (quiz[stanswercount].stAnswers.find(quiz[quizcount].quizAnswers))
            {
                AnswerCounterStudent++;
            }
            else
                AnswerCounterStudent--;
        }
    }

    switch (AnswerCounterStudent)
    {
    case 1:
        cout << "Bad" << endl;
        break;
    case 2:
        cout << "Bad" << endl;
        break;
    case 3:
        cout << "Average" << endl;
        break;
    case 4:
        cout << "Good" << endl;
        break;
    case 5:
        cout << "Very Good!" << endl;
        break;
    case 6:
        cout << "Excellent!" << endl;
        break;
    default:
        cout << "Absolutely Bad!" << endl;
        break;
    }
}

void gradingScale()
{
    cout << "|=======================|" << endl;
    cout << "1-2points - Bad" << endl;
    cout << "3points - Average" << endl;
    cout << "4points - Good" << endl;
    cout << "5points - Very Good!" << endl;
    cout << "6points - Excellent!" << endl;
    cout << "|=======================|" << endl;
}

bool studentMenu(QUIZ* quiz, int quizcount, int& maxId, int searchID, int stanswercount, int AnswerCounterStudent, int& quizAnswercount)
{
    cout << endl;                                     
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option!" << endl;
    cout << "1. View Quizes" << endl;
    cout << "2. Start Quiz" << endl;
    cout << "3. See your result" << endl;
    cout << "4. Grading scale" << endl;
	cout << "5. Go back to main menu" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option3;
    cin >> option3;

    switch (option3)
    {
    case 1:
        viewQuizName(quiz, quizcount, maxId);
        break;

    case 2:
        startQuiz(quiz, quizcount, maxId, searchID, stanswercount, quizAnswercount);
        break;

    case 3:
        checkStudentResult(quiz, quizcount, maxId, searchID, stanswercount, AnswerCounterStudent);
        break;

    case 4:
        gradingScale();
        break;

    case 5:
        return false;
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry3;
    }
	return true;
}

bool checkSystemStudent(string stUsernameTry, string stpasstry, QUIZ* quiz, int quizcount, int& maxId, int searchID, int stanswercount, int AnswerCounterStudent, ADMINISTRATOR* reg, int stCounter, int& quizAnswercount)
{
retry10:
    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "You must enter a valid username and password to access the student Menu !" << endl;
    cout << "Username: "; cin >> stUsernameTry;
    cout << "Pass: "; cin >> stpasstry;
    cout << "|============================================================================|" << endl;
    for (int i = 0; i < stCounter; i++)
    {
        if (stUsernameTry == reg[i].stUsername && stpasstry == reg[i].stPass) 
        {
            studentMenu(quiz, quizcount, maxId, searchID, stanswercount, AnswerCounterStudent, quizAnswercount);
        }
        else
        {
            cout << "Try Again !" << endl;
            goto retry10;
        }
    }
	return true;
}


// ---------------------------------------------------------------------------- Teacher ----------------------------------------------------------------------------



void deleteQuiz(QUIZ* quiz, int& quizcount, int& maxId, int searchID)
{
    for (int i = findIdQuiz(quiz, quizcount, maxId, searchID); i < quizcount - 1; i++)
    {
        quiz[i] = quiz[i + 1];
    }
    quizcount--;
}

void viewQuiz(QUIZ* quiz, int& quizcount, int& maxId, int& quizAnswercount)
{
    for (int i = 0; i < quizcount; i++)
    {
        cout << "|================================================|" << endl;
        cout << "Quiz Name: " << quiz[i].quizName;
        cout << endl;
        for (int j = 0; j < quiz[i].questionCount; j++)
        {
            cout << "[" << j << "]" << "Question: " << quiz[i].questions[j].title;
            cout << endl;
            cout << "Answer: " << quiz[i].questions[j].answer;
            cout << endl;
        }
        cout << "Quiz ID: "; cout << maxId;
        cout << endl;
        cout << "|================================================|" << endl;
        cout << endl;
    }
}

bool createQuiz(QUIZ* quiz, int& quizcount, int& maxId, int& quizAnswercount)
{
    cout << endl;
    cout << "|================================================|" << endl;
    cout << "Enter the name of the Quiz: "; cin.ignore(); getline(cin, quiz[quizcount].quizName);
    quizcount++;

retry7:
    cout << "Enter the amount of the questions: "; cin >> quiz[quizcount].questionCount;
    if (quiz[quizcount].questionCount > 0)
    {
        cin.ignore();
        for (int i = 0; i < quiz[quizcount].questionCount; i++)
        {
            cout << "[" << i << "]" << "Question: "; getline(cin, quiz[quizcount].questions[quiz[quizcount].questionCount].title);
            cout << "Answer: "; getline(cin, quiz[quizcount].questions[quiz[quizcount].questionCount].answer);
            quizAnswercount++;
        }
        cout << "|================================================|" << endl;

        idgenerator(maxId);
    }
    else
    {
        cout << "Incorrect Input" << endl;
        goto retry7;
    }
    return true;
}

bool teacherMenu(QUIZ* quiz, int& quizcount, int& maxId, int searchID, int& quizAnswercount)
{
    cout << endl;
    cout << "|==========================|" << endl;
    cout << "Welcome, choose an option !" << endl;
    cout << "1. Create Quiz" << endl;
    cout << "2. View Quizzes" << endl;
    cout << "3. Delete Quiz" << endl;
    cout << "5. Grading scale" << endl;
	cout << "6. Go back" << endl;
    cout << "|==========================|" << endl;

retry3:

    int option2;
    cin >> option2;

    switch (option2)
    {
    case 1:
        createQuiz(quiz, quizcount, maxId, quizAnswercount);
        break;

    case 2:
        viewQuiz(quiz, quizcount, maxId, quizAnswercount);
        break;

    case 3:
        deleteQuiz(quiz, quizcount, maxId, searchID);
        break;

    case 5:
        gradingScale();
        break;

	case 6:
		return false;
		break;

    default:
        cout << "Incorrect input" << endl;
        goto retry3;
    }
	return true;
}

bool checkSystemTeacher(string trPasstry, QUIZ* quiz, int& quizcount, int& maxId, int searchID, string trUsernameTry, ADMINISTRATOR* reg, int& trCounter, int& quizAnswercount)
{
retry2:
    cout << endl;
    cout << "|==================================================================|" << endl;
    cout << "You must enter a valid password to access the Teacher Menu !" << endl;
    cout << "Username: "; cin >> trUsernameTry;
    cout << "Pass: "; cin >> trPasstry;
    cout << "|==================================================================|" << endl;

    for (int i = 0; i < trCounter; i++)
    {
        if (trUsernameTry == reg[i].trUsername && trPasstry == reg[i].trPass)
        {
            teacherMenu(quiz, quizcount, maxId, searchID, quizAnswercount);
        }
        else
        {
            cout << "Try Again !" << endl;
            goto retry2;
        }
    }
	return true;
}

void exit()
{
	cout << endl;
	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
	cout << "*******    T H A N K  Y O U    *******" << endl;
	cout << "*******    F O R  U S I N G    *******" << endl;
	cout << "*******  O U R  P R O G R A M  *******" << endl;
	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
}

bool mainMenu(string trPasstry, string stUsernameTry, string stpasstry, string adminPass, string adminpasstry, ADMINISTRATOR* reg, int& stCounter, int& trCounter, int& searchID, int& maxId, int& quizcount, QUIZ* quiz, int& stanswercount, int& AnswerCounterStudent, string trUsernameTry, int& quizAnswercount)
{
    cout << endl;
    cout << "|======================|" << endl;
    cout << "Choose your character" << endl;
    cout << "1. Teacher" << endl; 
    cout << "2. Student" << endl; 
    cout << "3. Administrator" << endl; 
	cout << "4. Exit" << endl; 
    cout << "|======================|" << endl;

retry1:

    int option1;
    cin >> option1;

    switch (option1)
    {
    case 1:
        checkSystemTeacher(trPasstry, quiz, quizcount, maxId, searchID, trUsernameTry, reg, trCounter, quizAnswercount);
        break;

    case 2:
        checkSystemStudent(stUsernameTry, stpasstry, quiz, quizcount, maxId, searchID, stanswercount, AnswerCounterStudent, reg, stCounter, quizAnswercount);
        break;

    case 3:
        checkSystemAdministrator(adminPass, adminpasstry, reg, stCounter, trCounter, maxId, searchID);
        break;

	case 4:
		exit();
        return 0;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
	return true;
}

int main()
{
	ADMINISTRATOR reg[100];
	QUIZ quiz[100];

    int quizcount = 0;
    int quizAnswercount = 0;
    int stanswercount = 0;
    int AnswerCounterStudent = 0;

    //
    string trUsernameTry = "";
    string trPasstry = "";
    int trCounter = 0;

    string stUsernameTry = "";
    string stpasstry = "";
    int stCounter = 0;

    //
    string adminPass = "adminadmin";
    string adminpasstry = "";

    int maxId = 0;
    int searchID = 0;

	do {
		showMainMenu = mainMenu(trPasstry, stUsernameTry, stpasstry, adminPass, adminpasstry, reg, stCounter, trCounter, searchID, maxId, quizcount, quiz, stanswercount, AnswerCounterStudent, trUsernameTry, quizAnswercount);
	} while (showMainMenu != false);
}