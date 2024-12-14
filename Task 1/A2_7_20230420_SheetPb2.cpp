
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

class StringSet {
public:
    // Default constructor
    StringSet() {}

    // Helper function to convert a string to lowercase
    string toLowerCase(const string &input) {
        string result = input;
        for (char &c : result) {
            c = tolower(c);
        }
        return result;
    }

    // Vector to hold unique strings in the set
    vector<string> strings;

    // Constructor to initialize the set from a file or text
    StringSet(const string &input, bool isFilename) {
        if (isFilename) { // Load from file
            ifstream file(input);
            string line;
            while (getline(file, line)) {
                processLine(line);
            }
        } else { // Process directly from input string
            processLine(input);
        }
    }

    // Process a line of text to extract and store unique words
    void processLine(const string &text) {
        string result = "";
        for (char c : text) {
            // Replace non-alphanumeric characters with spaces
            if (isalnum(c) || c == ' ') {
                result += c;
            } else {
                result += " ";
            }
        }

        string word = "";
        for (char c : result) {
            if (c == ' ') {
                if (!word.empty()) {
                    // Add word if it's not already in the set
                    if (find(strings.begin(), strings.end(), toLowerCase(word)) == strings.end()) {
                        strings.push_back(toLowerCase(word));
                    }
                    word = "";
                }
            } else {
                word += c;
            }
        }

        // Add the last word if any
        if (!word.empty()) {
            if (find(strings.begin(), strings.end(), toLowerCase(word)) == strings.end()) {
                strings.push_back(toLowerCase(word));
            }
        }
    }

    // Add a new unique word to the set
    void addString(const string &word) {
        if (find(strings.begin(), strings.end(), word) == strings.end()) {
            strings.push_back(word);
        }
    }

    // Remove a word from the set
    void removeString(const string &word) {
        for (auto is = strings.begin(); is != strings.end(); ) {
            if (*is == word) {
                is = strings.erase(is);
            } else {
                ++is;
            }
        }
    }

    // Clear the entire set
    void clearEntireSet() {
        strings.clear();
    }

    // Print all strings in the set
    void printStrings() const {
        for (const auto &str : strings) {
            cout << str << " ";
        }
        cout << endl;
    }

    // Union of two StringSets
    StringSet operator+(const StringSet &other) {
        StringSet res;
        for (const string &word : this->strings) {
            if (find(res.strings.begin(), res.strings.end(), word) == res.strings.end()) {
                res.strings.push_back(word);
            }
        }
        for (const string &word : other.strings) {
            if (find(res.strings.begin(), res.strings.end(), word) == res.strings.end()) {
                res.strings.push_back(word);
            }
        }
        return res;
    }

    // Intersection of two StringSets
    StringSet operator*(const StringSet &other) {
        StringSet result;
        for (const string &word : this->strings) {
            if ((find(other.strings.begin(), other.strings.end(), word) != other.strings.end()) &&
                (find(result.strings.begin(), result.strings.end(), word) == result.strings.end())) {
                result.strings.push_back(word);
            }
        }
        return result;
    }

    // Calculate similarity between two sets using cosine similarity
    double calculateSimilarity(const StringSet& q) {
        int n = (this->operator*(q)).strings.size(); // Intersection size
        int d = this->strings.size(); // Size of first set
        int Q = q.strings.size(); // Size of second set

        double similarity = static_cast<double>(n) / (sqrt(d) * sqrt(Q));
        return similarity;
    }
};

// Perform operations on two StringSets
void performOperations(StringSet& set1, StringSet& set2) {
    while (true) {
        cout << "\nCurrent set (set1): ";
        set1.printStrings();

        cout << "\nChoose an operation:\n";
        cout << "1: Merge two texts (Union)\n";
        cout << "2: Calculate similarity between texts\n";
        cout << "3: Calculate intersection of texts\n";
        cout << "4: Add a word to the set (set1)\n";
        cout << "5: Remove a word from the set (set1)\n";
        cout << "6: Clear the set (set1)\n";
        cout << "7: Return to main menu\n";

        int subchoice;
        cin >> subchoice;

        if (subchoice == 1) { // Union
            StringSet merged = set1 + set2;
            cout << "Merged text: ";
            merged.printStrings();
        } else if (subchoice == 2) { // Similarity
            double similarity = set1.calculateSimilarity(set2);
            cout << "Similarity between the texts: " << similarity << endl;
        } else if (subchoice == 3) { // Intersection
            StringSet intersection = set1 * set2;
            cout << "Intersection of the texts: ";
            intersection.printStrings();
        } else if (subchoice == 4) { // Add word
            string word;
            cout << "Enter a word to add to set1: ";
            cin >> word;
            set1.addString(word);
            cout << "Updated set1: ";
            set1.printStrings();
        } else if (subchoice == 5) { // Remove word
            string word;
            cout << "Enter a word to remove from set1: ";
            cin >> word;
            set1.removeString(word);
            cout << "Updated set1: ";
            set1.printStrings();
        } else if (subchoice == 6) { // Clear set
            set1.clearEntireSet();
            cout << "Set1 cleared." << endl;
        } else if (subchoice == 7) { // Return to menu
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function to handle user input and manage operations
int main() {
    StringSet set1;
    StringSet set2;
    while (true) {
        cout << "Select from the menu:\n";
        cout << "1: Load two files\n";
        cout << "2: Enter two texts\n";
        cout << "3: Perform operations on the texts\n";
        cout << "4: Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1) { // Load files
            string file1, file2;
            cout << "Enter the first filename: ";
            cin >> file1;
            cout << "Enter the second filename: ";
            cin >> file2;

            set1 = StringSet(file1, true);
            set2 = StringSet(file2, true);

            cout << "Words in the first file:\n";
            set1.printStrings();
            cout << "Words in the second file:\n";
            set2.printStrings();

            StringSet intersection = set1 * set2;
            cout << "Common words: ";
            intersection.printStrings();
            StringSet Union =set1+set2;
            cout<<"merged words: ";
            Union.printStrings();

            double similarity = set1.calculateSimilarity(set2);
            cout << "Similarity between the files: " << similarity << endl;

        } else if (choice == 2) { // Enter texts
            string string1, string2;
            cout << "Enter the first text: ";
            cin.ignore();
            getline(cin, string1);
            cout << "Enter the second text: ";
            getline(cin, string2);

            set1 = StringSet(string1, false);
            set2 = StringSet(string2, false);

            cout << "Words in the first text:\n";
            set1.printStrings();
            cout << "Words in the second text:\n";
            set2.printStrings();

            StringSet intersection = set1 * set2;
            cout << "Common words: ";
            intersection.printStrings();
              StringSet Union =set1+set2;
            cout<<"merged words: ";
            Union.printStrings();

            double similarity = set1.calculateSimilarity(set2);
            cout << "Similarity between the texts: " << similarity << endl;

        } else if (choice == 3) { // Perform operations
            if (set1.strings.empty() || set2.strings.empty()) {
                cout << "Please load two sets first (choose option 1 or 2).\n";
            } else {
                performOperations(set1, set2);
            }
        } else if (choice == 4) { // Exit
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
                
