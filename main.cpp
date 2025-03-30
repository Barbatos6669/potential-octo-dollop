#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task
{
    public:
        string name;
        string description;

        // Constructor
        Task(string n, string d) 
        {
            name = n;
            description = d;
        }

        void display()
        {
            cout << name << " - " << description << endl;
        }

};

int main() 
{
    int menuChoice = 0;

    while (menuChoice != 4)
        {
            cout << "To-do list" << endl;
            cout << "1. Add task" << endl;
            cout << "2. Remove task" << endl;
            cout << "3. View tasks" << endl;
            cout << "4. Exit" << endl;      

            cin >> menuChoice;

            switch (menuChoice)
            {
            case 1: {
                string taskName, taskDescription;
                int addTaskChoice = 0;

                cout << "Enter Task Name: ";
                cin >> taskName;
                cout << "Enter Task Description: ";
                cin >> taskDescription;

                cout << endl;
                cout << "Added Task: " << taskName << " - " << taskDescription << endl;
                cout << endl;

                cout << "Create another task" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;

                cin >> addTaskChoice;

                if (addTaskChoice == 2) {
                    cout << "Going back to main menu....." << endl;
                }
                break;
            }
            case 2:
                cout << "Remove Task selected" << endl;
                break;
            case 3:
                cout << "View Task Selected" << endl;
                break;
            case 4:
                cout << "Exit selected....Goodbye" << endl;
                break;
            default:
                break;
            }
        }

    return 0;
}

