
#include <iostream>
using namespace std;


bool mainMenu()
{

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
        //Function
        break;

    case 2:
        //Function
        break;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
}

int main()
{
    
}