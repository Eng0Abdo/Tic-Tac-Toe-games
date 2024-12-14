#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

void clean(string &word) {
    string cleanedWord;
    int len = word.length();

    if (word[0] == '-') {
        word = word.substr(1);
        len--;
    }
    if (word[len - 1] == '-') {
        word = word.substr(0, len - 1);
        len--;
    }

    for (char ch : word) {
        if (isalnum(ch) || ch == '-') {
            cleanedWord += tolower(ch);
        }
    }

    size_t pos = cleanedWord.find('-');
    if (pos != string::npos) {

        if (pos > 0 && pos < cleanedWord.length() - 1 && isalnum(cleanedWord[pos - 1]) && isalnum(cleanedWord[pos + 1])) {
            word = cleanedWord;
        } else {
            word = cleanedWord.substr(0, pos) + cleanedWord.substr(pos + 1);
        }
    } else {
        word = cleanedWord;
    }
}

void Read(ifstream &file) {
    map<string, int> wordCount;
    string word;

    while (file >> word) {
        clean(word);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    if (wordCount.empty()) {
        cout << "The file doesn't contain any words!" << endl;
    } else {
        cout << "Word Frequency Table:" << endl;
        for (const auto &entry : wordCount) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
}

int main() {
    string filename;
    cout << "Enter the filename with (.txt): ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "File opened successfully!" << endl;

    Read(file);

    file.close();
    return 0;
}
