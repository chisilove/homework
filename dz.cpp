#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    int age;
    double weight;

public:
    Pet(string name, int age, double weight){}

    virtual void showInfo() const {
        cout << "імя: " << name << "\n";
        cout << "вік: " << age << " р.\n";
        cout << "вага: " << weight << " кг\n";
    }

    virtual ~Pet() {}
};

class Dog : public Pet {
private:
    string breed;

public:
    Dog(string name, int age, double weight, string breed){}

    void showInfo() const override {
        cout << "собака\n";
        Pet::showInfo();
        cout << "порода: " << breed << "\n";
    }
};

class Cat : public Pet {
private:
    string furColor;

public:
    Cat(string name, int age, double weight, string color){}

    void showInfo() const override {
        cout << "кішка\n";
        Pet::showInfo();
        cout << "колір шерсті: " << furColor << "\n";
    }
};

class Parrot : public Pet {

public:
    Parrot(string name, int age, double weight){}

    void showInfo() const override {
        cout << "папуга\n";
        Pet::showInfo();
    }
};

int main() {
    Dog myDog("рекс", 4, 28.5, "чіхуахуа");
    Cat myCat("мурка", 2, 3.8, "рижий");
    Parrot myParrot("кеша", 1, 0.15);

    myDog.showInfo();
    myCat.showInfo();
    myParrot.showInfo();

    return 0;
}