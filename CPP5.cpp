#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ofstream outFile("original.txt");

    if (!outFile.is_open()) {
        cout << "Error: Cannot create original.txt" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;

    outFile.close();

    ifstream inFile("original.txt");

    if (!inFile.is_open()) {
        cout << "Error: Cannot open original.txt" << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile.is_open()) {
        cout << "Error: Cannot create sorted.txt" << endl;
        return 1;
    }

    for (const string& word : words) {
        sortedFile << word << endl;
    }

    sortedFile.close();

    cout << "Sorting completed. Check sorted.txt" << endl;

    return 0;
}