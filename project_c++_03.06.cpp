#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
struct Task {
    char name[100];
    int priority;
    bool isCompleted;
};

const char FILE_NAME[] = "your file";
const int MAX_TASKS = 100;

void loadTasks(vector<Task>& tasks) {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return;
    }
     countTasks = 0;
while (countTasks < MAX_TASKS &&
           file >> tasks[countTasks].isCompleted >> tasks[countTasks].priority) {
        file.ignore();
        file.getline(tasks[countTasks].name, 100);
        countTasks++;
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


void printTask(int index, Task task) {
    cout << "[" << index + 1 << "] ";
    if (task.isCompleted) {
        cout << "[X] ";
    }
    else {
        cout << "[ ] ";
    }
    cout << "Priority: " << task.priority << " | ";
    cout << task.name << "\n";
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Task tasks[MAX_TASKS];
    int countTasks = 0;

    loadTasks(tasks, countTasks);

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
            
if (countTasks >= MAX_TASKS) {
                cout << "too many cases\n";
            }
            else {
                cout << "enter name case: ";
                cin.ignore();
                cin.getline(tasks[countTasks].name, 100);

                cout << "enter priority (1 high, 2 mid, 3 low): ";
                cin >> tasks[countTasks].priority;

                tasks[countTasks].isCompleted = false;

                countTasks++;

                saveTasks(tasks, countTasks);

                cout << "case added\n";
            }
        }
        else if (choice == 2) {
            cout << "\nall case\n";

            if (countTasks == 0) {
                cout << "list empty\n";
            }

            for (int i = 0; i < countTasks; i++) {
                printTask(i, tasks[i]);
            }
        }
        else if (choice == 3) {
            cout << "\nuncomplete cases\n";

            bool found = false;

            for (int i = 0; i < countTasks; i++) {
                if (tasks[i].isCompleted == false) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }

            if (found == false) {
                cout << "all case completed\n";
            }
        }
        else if (choice == 4) {
            int num;

            cout << "enter number of case, mark as completed: ";
            cin >> num;

            if (num > 0 && num <= countTasks) {
                tasks[num - 1].isCompleted = true;

                saveTasks(tasks, countTasks);

                cout << "status updated\n";
            }
            else {
                cout << "wrong number\n";
            }
        }
        else if (choice == 5) {
            int num;

            cout << "enter number case for delete: ";
            cin >> num;

            if (num > 0 && num <= countTasks) {
                for (int i = num - 1; i < countTasks - 1; i++) {
                    tasks[i] = tasks[i + 1];
                }

                countTasks--;

                saveTasks(tasks, countTasks);

                cout << "case deleted\n";
            }
            else {
                cout << "wrong number\n";
            }
        }
        else if (choice == 6) {
            int p;

            cout << "enter priority for search (1, 2 or 3): ";
            cin >> p;

            cout << "\ncase with priority " << p << "\n";

            bool found = false;

            for (int i = 0; i < countTasks; i++) {
                if (tasks[i].priority == p) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }

            if (found == false) {
                cout << "case with this priority not found\n";
            }
        }
        else if (choice == 7) {
            saveTasks(tasks, countTasks);

            cout << "information saved in file " << FILE_NAME << "\n";
        }
        else if (choice == 8) {
            saveTasks(tasks, countTasks);

            cout << "good bye\n";
        }
        else {
            cout << "wrong command retry\n";
        }


    return 0;
}
