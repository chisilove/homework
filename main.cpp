#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;    

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int pos, int value) {
        if (pos < 0 || pos > size) {
            cout << "еррор невірна позиція для вставки\n";
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "ерор неправильна позиція для видалення";
            return;
        }

        Node* nodeToDelete = nullptr;

        if (pos == 0) {
            nodeToDelete = head;
            head = head->next;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            nodeToDelete = current->next;
            current->next = nodeToDelete->next;
        }

        delete nodeToDelete;
        size--;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << еррор індекс " << index << " вийшов за межі списку\n";
            static int dummy = 0;
            return dummy;
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        Node* current = list.head;
        os << "[";
        while (current != nullptr) {
            os << current->data;
            if (current->next != nullptr) {
                os << " -> ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    LinkedList list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);

    cout << "список: " << list << "\n";

    cout << "eлемент [2]: " << list[2] << "\n";
    list[2] = 25;
    cout << "cписок після зміни: " << list << "\n";

    cout << "звернення до [10]: " << list[10] << "\n";

    list.removeAt(0);
    cout << "після видалення [0]: " << list << "\n";

    return 0;
}