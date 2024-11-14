#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
    vector<string> stringLines;

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

    vector<string> splitIntoLines(string& content) {
        stringLines.clear();
        stringstream s(content);
        string line;
        while (getline(s, line)) {
            stringLines.push_back(line);
        }
        return stringLines;
    }

    string nextLabel() {
        string labelStr = label + to_string(labelNum);
        if (labelNum - 1 < stringLines.size()) {
            labelStr += " " + stringLines[labelNum - 1];
        }
        labelNum++;
        return labelStr;
    }
};

int main() {
    labelGenerator figureNumbers("Figure ", 1);
    labelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;

    fileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }

    return 0;
}
