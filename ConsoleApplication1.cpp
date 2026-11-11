#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

string cleanWord(const string& rawWord) {
   string cleaned = "";
    for (char ch : rawWord) {
        if (isalnum(static_cast<unsigned char>(ch))) {
            cleaned += static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }
    }
    return cleaned;
}

int main() {
    const string inputFilename = " ";
    const string outputFilename = " ";

    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "error: cant open file " << inputFilename;
        return 1;
    }

    map<string, int> frequencyMap;
    string rawWord;

    while (inputFile >> rawWord) {
        string word = cleanWord(rawWord);
        if (!word.empty()) {
            frequencyMap[word]++;
        }
    }
    inputFile.close();

    if (frequencyMap.empty()) {
        cout << "file empty";
        return 0;
    }

    string mostFrequentWord = "";
    int maxCount = 0;

    for (const auto& pair : frequencyMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    cout << "words";
    for (const auto& pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    cout << "must used word: " << mostFrequentWord
        << " (кількість появ: " << maxCount << ")";

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "erro: cant open or crate file" << outputFilename << " for writing";
        return 1;
    }

    outputFile << "result";
    for (const auto& pair : frequencyMap) {
        outputFile << pair.first << ": " << pair.second << "\n";
    }

    outputFile << "most used word: " << mostFrequentWord
        << " (кількість появ: " << maxCount << ")";

    outputFile.close();
    cout << "result succeful: " << outputFilename;

    return 0;
}