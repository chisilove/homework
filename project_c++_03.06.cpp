#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
struct Task {
    string name;
    int priority;
    bool isCompleted;
};

const string FILE_NAME = "any directory";
void loadTasks(vector<Task>& tasks) {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return;
    }

    Task tempTask;
    while (file >> tempTask.isCompleted >> tempTask.priority) {
        getline(file >> ws, tempTask.name);
        tasks.push_back(tempTask);
    }
    file.close();
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file(FILE_NAME);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.isCompleted << " " << task.priority << " " << task.name << "\n";
        }
        file.close();
    }
    else {
        cout << "erorr save in file\n";
    }
}

void printTask(int index, const Task& task) {
    cout << "[" << index + 1 << "] ";
    cout << (task.isCompleted ? "[X] " : "[ ] ");
    cout << "Priority: " << task.priority << " | " << task.name << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Task> tasks;
    loadTasks(tasks);

    int choice = 0;

    while (choice != 8) {
        cout << "\ncase planer\n";
        cout << "1.add case\n";
        cout << "2.show all case\n";
        cout << "3.show only not complete\n";
        cout << "4.mark complete\n";
        cout << "5.delete case\n";
        cout << "6.seacrh with priority\n";
        cout << "7.save in file (self)\n";
        cout << "8.exit\n";
        cout << "enter: ";
        cin >> choice;

        if (choice == 1) {
            Task newTask;
            cout << "enter name case: ";
            getline(cin >> ws, newTask.name);
            cout << "enter priority (1 high, 2 mid, 3 low): ";
            cin >> newTask.priority;
            newTask.isCompleted = false;

            tasks.push_back(newTask);
            saveTasks(tasks);
            cout << "case added\n";

        }
        else if (choice == 2) {
            cout << "\nall case\n";
            if (tasks.empty()) cout << "list empty\n";
            for (int i = 0; i < tasks.size(); i++) {
                printTask(i, tasks[i]);
            }

        }
        else if (choice == 3) {
            cout << "\nuncomplete cases\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (!tasks[i].isCompleted) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "all case completed\n";

        }
        else if (choice == 4) {
            cout << "enter number of case, mark as completed: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].isCompleted = true;
                saveTasks(tasks);
                cout << "status updated\n";
            }
            else {
                cout << "wrong number\n";
            }

        }
        else if (choice == 5) {
            cout << "enter number case for delete: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                
                tasks.erase(tasks.begin() + num - 1);
                saveTasks(tasks);
                cout << "case deleted\n";
            }
            else {
                cout << "wrong number\n";
            }

        }
        else if (choice == 6) {
            cout << "enter priority for seacrh (1, 2 or 3): ";
            int p;
            cin >> p;
            cout << "\ncase with priority" << p << "\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].priority == p) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "case with this priority not found\n";

        }
        else if (choice == 7) {
            saveTasks(tasks);
            cout << "information saved in file " << FILE_NAME << "\n";

        }
        else if (choice == 8) {
            saveTasks(tasks);
            cout << "good bye\n";
        }
        else {
            cout << "wrong command retry\n";
        }
    }

    return 0;
}
