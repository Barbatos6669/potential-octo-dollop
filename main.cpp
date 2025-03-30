#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    int id;
    string name;
    string description;

    Task(int i, string n, string d) {
        id = i;
        name = n;
        description = d;
    }

    void display() const {
        cout << id << ".) " << name << " - " << description << endl;
    }
};

int main() {
    vector<Task> tasks;
    int menuChoice = 0;
    int nextId = 1;

    while (menuChoice != 4) {
        cout << "\nTo-do list" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. View tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> menuChoice;

        switch (menuChoice) {
        case 1: {
            cin.ignore(); // Clear newline
            string taskName, taskDescription;

            cout << "Task Name: ";
            getline(cin, taskName);

            cout << "Task Description: ";
            getline(cin, taskDescription);

            tasks.push_back(Task(nextId, taskName, taskDescription));
            cout << "Task added successfully!" << endl;
            nextId++;

            break;
        }
        case 2: {
            if (tasks.empty()) {
                cout << "No tasks to remove." << endl;
                break;
            }

            int idToRemove;
            cout << "Enter task ID to remove: ";
            cin >> idToRemove;

            bool found = false;
            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                if (it->id == idToRemove) {
                    tasks.erase(it);
                    cout << "Task removed successfully!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Task ID not found." << endl;
            }

            break;
        }
        case 3: {
            if (tasks.empty()) {
                cout << "No tasks in the list." << endl;
            } else {
                cout << "\nIncomplete tasks:\n";
                for (const auto& task : tasks) {
                    task.display();
                }
            }
            break;
        }
        case 4:
            cout << "Exit selected....Goodbye" << endl;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
            break;
        }
    }

    return 0;
}
