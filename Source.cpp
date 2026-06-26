#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("enter your file");

    if (!inputFile.is_open()) {
        cout << "erorr cant open file" << "\n";
        return 1;
    }

    vector<string> words; 
    string word; 

    while (inputFile >> word) {
        words.push_back(word); 
    }

    inputFile.close();
    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cout << "error cant create file" << "\n";
        return 1;
    }

    for (int i = words.size() - 1; i >= 0; i--) {
        outputFile << words[i] << " ";
    }

    outputFile.close();

    cout << "Succeful words writen in invert poradku in file" << "\n";
    return 0;
}