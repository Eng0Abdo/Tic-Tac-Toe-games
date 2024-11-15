#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <cstdlib>
using namespace std;

class labelGenerator {
protected:
    string label;
    int labelNum;

public:
    labelGenerator() : label("Label "), labelNum(1) {}

    labelGenerator(string inputLabel, int inputLabelNum) : label(inputLabel), labelNum(inputLabelNum) {}

    string nextLabel() {
        return label + to_string(labelNum++);
    }
};

class fileLabelGenerator : public labelGenerator {
protected:
    string fileName;
    string fileContent;
    queue<string> headerQueue;

public:
    fileLabelGenerator() : labelGenerator(), fileName("file") {}

    fileLabelGenerator(string inputLabel, int inputLabelNum, string inputFileName)
        : labelGenerator(inputLabel, inputLabelNum), fileName(inputFileName) {
        fileContent = read();
        splitIntoLines(fileContent);
    }

    string read() {
        fstream file;
        file.open(fileName);
        if (!file) {
            cout << "File not found, please make sure that you entered the correct file name!" << endl;
            return "";
        }
        stringstream f_content;
        f_content << file.rdbuf();
        fileContent = f_content.str();
        file.close();
        return fileContent;
    }

    void splitIntoLines(string& content) {
        stringstream s(content);
        string line;
        while (getline(s, line)) {
            headerQueue.push(line);
        }
    }

    string nextLabel() {
        string labelStr = label + to_string(labelNum++);
        if (!headerQueue.empty()) {
            labelStr += " " + headerQueue.front();
            headerQueue.pop();
        }
        return labelStr;
    }
};

void menu() {
    while (true) {
        char choice;
        cout << "Welcome! Please choose an option:" << endl;
        cout << "[A] Create labels without heads" << endl;
        cout << "[B] Create labels with heads" << endl;
        cout << "[C] Exit" << endl;
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'a') {
            char secChoice;
            string label;
            int rep, startFrom = 1;

            cout << "[A] Standard labels starting from 1" << endl;
            cout << "[B] Custom labels" << endl;
            cin >> secChoice;
            secChoice = tolower(secChoice);

            if (secChoice == 'a') {
                cout << "Enter your label format: ";
                cin >> label;
                cout << "Enter the number of labels: ";
                cin >> rep;
                labelGenerator generator(label + " ", 1);

                for (int i = 0; i < rep; ++i) {
                    cout << generator.nextLabel() << endl;
                }
            }
            else if (secChoice == 'b') {
                cout << "Enter your label format: ";
                cin >> label;
                cout << "Enter starting number: ";
                cin >> startFrom;
                cout << "Enter the number of labels: ";
                cin >> rep;
                labelGenerator generator(label + " ", startFrom);

                for (int i = 0; i < rep; ++i) {
                    cout << generator.nextLabel() << endl;
                }
            }
            else {
                cout << "Invalid choice. Returning to main menu." << endl;
            }

        }
        else if (choice == 'b') {
            char secChoice;
            string label, fileName;
            int rep, startFrom = 1;

            cout << "[A] Standard labels starting from 1" << endl;
            cout << "[B] Custom labels" << endl;
            cin >> secChoice;
            secChoice = tolower(secChoice);

            if (secChoice == 'a') {
                cout << "Enter your label format: ";
                cin >> label;
                cout << "Enter the number of labels: ";
                cin >> rep;
                cout << "Enter the file name for headers: ";
                cin >> fileName;
                fileLabelGenerator generator(label + " ", 1, fileName);

                for (int i = 0; i < rep; ++i) {
                    cout << generator.nextLabel() << endl;
                }
            }
            else if (secChoice == 'b') {
                cout << "Enter your label format: ";
                cin >> label;
                cout << "Enter starting number: ";
                cin >> startFrom;
                cout << "Enter the file name for headers: ";
                cin >> fileName;
                cout << "Enter the number of labels: ";
                cin >> rep;
                fileLabelGenerator generator(label + " ", startFrom, fileName);

                for (int i = 0; i < rep; ++i) {
                    cout << generator.nextLabel() << endl;
                }
            }
            else {
                cout << "Invalid choice. Returning to main menu." << endl;
            }

        }
        else if (choice == 'c') {
            cout << "Exiting program. Goodbye!" << endl;
            exit(0);

        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}



int main() {
    menu();
    return 0;
}
