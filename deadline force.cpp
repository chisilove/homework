#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

class FileViewer {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file.is_open()) {
            cout << "ерор: не вдалося відкрити файл" << endl;
            return;
        }
        
        char ch;
        cout << "вивід файлу" << endl;
        while (file.get(ch)) {
            cout << ch;
        }
        cout<< endl;
        file.close();
    }
};

class AsciiViewer : public FileViewer {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cout << "ерор: не вдалося відкрити файл";
            return;
        }

        char ch;
        cout << "вивід в кодах assci";
        while (file.get(ch)) {
            cout << (int)ch << " ";
        }
        cout <<;
        file.close();
    }
};

class BinaryViewer : public FileViewer {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cout << "ерор: не вдалося відкрити файл" << endl;
            return;
        }

        char ch;
        cout << "двійковий вивід";
        while (file.get(ch)) {

            cout << bitset<8>(ch) << " ";
        }
        cout << endl << endl;
        file.close();
    }
};

int main() {
    const char* filepath = "C:\\Users\\teilm\\Desktop\\123.txt"; 
    
    FileViewer* viewer1 = new FileViewer();
    FileViewer* viewer2 = new AsciiViewer();
    FileViewer* viewer3 = new BinaryViewer();

    viewer1->Display(filepath);
    viewer2->Display(filepath);
    viewer3->Display(filepath);

    delete viewer1;
    delete viewer2;
    delete viewer3;

    return 0;
}