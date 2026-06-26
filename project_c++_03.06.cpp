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

const string FILE_NAME = "люба директорiя файлу ";
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
        cout << "Помилка збереження у файл\n";
    }
}

void printTask(int index, const Task& task) {
    cout << "[" << index + 1 << "] ";
    cout << (task.isCompleted ? "[X] " : "[ ] ");
    cout << "Пріоритет: " << task.priority << " | " << task.name << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Task> tasks;
    loadTasks(tasks);

    int choice = 0;

    while (choice != 8) {
        cout << "\nПланувальник Спрва\n";
        cout << "1.Додати задачу\n";
        cout << "2.Показати всі задачі\n";
        cout << "3.Показати тільки невиконані\n";
        cout << "4.Позначити як виконану\n";
        cout << "5.Видалити задачу\n";
        cout << "6.Пошук за пріоритетом\n";
        cout << "7.Зберегти у файл (вручну)\n";
        cout << "8.Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            Task newTask;
            cout << "Введіть назву задачі: ";
            getline(cin >> ws, newTask.name);
            cout << "Введіть пріоритет (1 Високий, 2 Середній, 3 Низький): ";
            cin >> newTask.priority;
            newTask.isCompleted = false;

            tasks.push_back(newTask);
            saveTasks(tasks);
            cout << "Задачу додано\n";

        }
        else if (choice == 2) {
            cout << "\nВсі задачі\n";
            if (tasks.empty()) cout << "Список порожній\n";
            for (int i = 0; i < tasks.size(); i++) {
                printTask(i, tasks[i]);
            }

        }
        else if (choice == 3) {
            cout << "\nНевиконані задачі\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (!tasks[i].isCompleted) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "Усі задачі виконані\n";

        }
        else if (choice == 4) {
            cout << "Введіть номер задачі, щоб позначити як виконану: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].isCompleted = true;
                saveTasks(tasks);
                cout << "Статус оновлено\n";
            }
            else {
                cout << "Невірний номер\n";
            }

        }
        else if (choice == 5) {
            cout << "Введіть номер задачі для видалення: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                
                tasks.erase(tasks.begin() + num - 1);
                saveTasks(tasks);
                cout << "Задачу видалено\n";
            }
            else {
                cout << "Невірний номер\n";
            }

        }
        else if (choice == 6) {
            cout << "Введіть пріоритет для пошуку (1, 2 або 3): ";
            int p;
            cin >> p;
            cout << "\nЗадачі з пріоритетом" << p << "\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].priority == p) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "Задач з таким пріоритетом не знайдено\n";

        }
        else if (choice == 7) {
            saveTasks(tasks);
            cout << "Дані збережено у файл " << FILE_NAME << "\n";

        }
        else if (choice == 8) {
            saveTasks(tasks);
            cout << "До побачення\n";
        }
        else {
            cout << "Невірна команда пробуйте ще раз\n";
        }
    }

    return 0;
}