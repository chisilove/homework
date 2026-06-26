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

const string FILE_NAME = "ëþáà äèðåêòîðiÿ ôàéëó ";
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
        cout << "Ïîìèëêà çáåðåæåííÿ ó ôàéë\n";
    }
}

void printTask(int index, const Task& task) {
    cout << "[" << index + 1 << "] ";
    cout << (task.isCompleted ? "[X] " : "[ ] ");
    cout << "Ïð³îðèòåò: " << task.priority << " | " << task.name << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Task> tasks;
    loadTasks(tasks);

    int choice = 0;

    while (choice != 8) {
        cout << "\nÏëàíóâàëüíèê Ñïðâà\n";
        cout << "1.Äîäàòè çàäà÷ó\n";
        cout << "2.Ïîêàçàòè âñ³ çàäà÷³\n";
        cout << "3.Ïîêàçàòè ò³ëüêè íåâèêîíàí³\n";
        cout << "4.Ïîçíà÷èòè ÿê âèêîíàíó\n";
        cout << "5.Âèäàëèòè çàäà÷ó\n";
        cout << "6.Ïîøóê çà ïð³îðèòåòîì\n";
        cout << "7.Çáåðåãòè ó ôàéë (âðó÷íó)\n";
        cout << "8.Âèéòè\n";
        cout << "Âàø âèá³ð: ";
        cin >> choice;

        if (choice == 1) {
            Task newTask;
            cout << "Ââåä³òü íàçâó çàäà÷³: ";
            getline(cin >> ws, newTask.name);
            cout << "Ââåä³òü ïð³îðèòåò (1 Âèñîêèé, 2 Ñåðåäí³é, 3 Íèçüêèé): ";
            cin >> newTask.priority;
            newTask.isCompleted = false;

            tasks.push_back(newTask);
            saveTasks(tasks);
            cout << "Çàäà÷ó äîäàíî\n";

        }
        else if (choice == 2) {
            cout << "\nÂñ³ çàäà÷³\n";
            if (tasks.empty()) cout << "Ñïèñîê ïîðîæí³é\n";
            for (int i = 0; i < tasks.size(); i++) {
                printTask(i, tasks[i]);
            }

        }
        else if (choice == 3) {
            cout << "\nÍåâèêîíàí³ çàäà÷³\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (!tasks[i].isCompleted) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "Óñ³ çàäà÷³ âèêîíàí³\n";

        }
        else if (choice == 4) {
            cout << "Ââåä³òü íîìåð çàäà÷³, ùîá ïîçíà÷èòè ÿê âèêîíàíó: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].isCompleted = true;
                saveTasks(tasks);
                cout << "Ñòàòóñ îíîâëåíî\n";
            }
            else {
                cout << "Íåâ³ðíèé íîìåð\n";
            }

        }
        else if (choice == 5) {
            cout << "Ââåä³òü íîìåð çàäà÷³ äëÿ âèäàëåííÿ: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                
                tasks.erase(tasks.begin() + num - 1);
                saveTasks(tasks);
                cout << "Çàäà÷ó âèäàëåíî\n";
            }
            else {
                cout << "Íåâ³ðíèé íîìåð\n";
            }

        }
        else if (choice == 6) {
            cout << "Ââåä³òü ïð³îðèòåò äëÿ ïîøóêó (1, 2 àáî 3): ";
            int p;
            cin >> p;
            cout << "\nÇàäà÷³ ç ïð³îðèòåòîì" << p << "\n";
            bool found = false;
            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i].priority == p) {
                    printTask(i, tasks[i]);
                    found = true;
                }
            }
            if (!found) cout << "Çàäà÷ ç òàêèì ïð³îðèòåòîì íå çíàéäåíî\n";

        }
        else if (choice == 7) {
            saveTasks(tasks);
            cout << "Äàí³ çáåðåæåíî ó ôàéë " << FILE_NAME << "\n";

        }
        else if (choice == 8) {
            saveTasks(tasks);
            cout << "Äî ïîáà÷åííÿ\n";
        }
        else {
            cout << "Íåâ³ðíà êîìàíäà ïðîáóéòå ùå ðàç\n";
        }
    }

    return 0;
}
