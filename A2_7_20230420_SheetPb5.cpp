

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

class process {
public:
    string name;
    int pid;
    string sessionName;
    int sessionNumber;
    int memoreyusage;

    // Constructor to initialize a process
    process(string nam, int id, string session, int sessionNum, int memo) {
        name = nam;
        pid = id;
        sessionName = session;
        sessionNumber = sessionNum;
        memoreyusage = memo;
    }

    // Getters for process attributes
    string getname() const { return name; }
    int getpid() const { return pid; }
    string getsessionName() const { return sessionName; }
    int getsessionNumber() const { return sessionNumber; }
    int getusage() const { return memoreyusage; }
};

class processlist {
public:
    vector<process> pro, pro2;

    void loadprocess() {
        system("tasklist > proces.txt");
        ifstream file("proces.txt");
        string line;

        // Skip the first 3 header lines
        for (int p = 0; p < 3; p++) {
            getline(file, line);
        }

        while (getline(file, line)) {
            string name = "", pid , sessionName, sessionNum , usag ;
            vector<string> tokens;
            stringstream pp(line);
            string token;

            // Split the line into words (tokens)
            while (pp >> token) {
                tokens.push_back(token);
            }

                
                name = tokens[0];
                int i = 1;
                while (!isdigit(tokens[i][0]) && i < tokens.size() - 4) {
                    name += " " + tokens[i];
                    i++;
                }

                // Extract PID, Session Name, Session Number, and Memory Usage
                pid = tokens[i++];
                sessionName = tokens[i++];
                sessionNum = tokens[i++];
                usag = tokens[tokens.size() - 2];
            

            // Clean memory usage value
            usag.erase(remove(usag.begin(), usag.end(), ','), usag.end());
            if (!usag.empty() && usag.back() == 'K') {
                usag.pop_back();
            }

            // Convert values to integers
            int ppid = stoi(pid);
            int session_number = stoi(sessionNum);
            int uusag = stoi(usag);

            pro.push_back(process(name, ppid, sessionName, session_number, uusag));
            pro2.push_back(process(name, ppid, sessionName, session_number, uusag));
        }
    }

    void showprocess() {
        // Print table headers
        cout << left << setw(30) << "Name" 
             << setw(15) << "PID" 
             << setw(20) << "Session Name" 
             << setw(15) << "Session Number" 
             << setw(20) << "Memory Usage (KB)" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;

        // Print each process's details
        for (int i = 0; i < pro.size(); i++) {
            cout << left << setw(30) << pro[i].getname()
                 << setw(15) << pro[i].getpid()
                 << setw(20) << pro[i].getsessionName()
                 << setw(15) << pro[i].getsessionNumber()
                 << setw(20) << (to_string(pro[i].getusage()) + " K") << endl;
        }
    }

    void printprocess() {
        // Print table headers
        cout << left << setw(30) << "Name" 
             << setw(15) << "PID" 
             << setw(20) << "Session Name" 
             << setw(15) << "Session Number" 
             << setw(20) << "Memory Usage (KB)" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;

        // Print each process's details
        for (int i = 0; i < pro2.size(); i++) {
            cout << left << setw(30) << pro2[i].getname()
                 << setw(15) << pro2[i].getpid()
                 << setw(20) << pro2[i].getsessionName()
                 << setw(15) << pro2[i].getsessionNumber()
                 << setw(20) << (to_string(pro2[i].getusage()) + " K") << endl;
        }
    }

    void sortByName() {
        sort(pro.begin(), pro.end(), [](const process &p1, const process &p2) {
            return p1.getname() < p2.getname();
        });
    }

    void sortByPid() {
        sort(pro.begin(), pro.end(), [](const process &p1, const process &p2) {
            return p1.getpid() < p2.getpid();
        });
    }

    void sortByMemoryUsage() {
        sort(pro.begin(), pro.end(), [](const process &p1, const process &p2) {
            return p1.getusage() < p2.getusage();
        });
    }
};

int main() {
    processlist p;
    p.loadprocess();

    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1: Sort by Name\n";
        cout << "2: Sort by PID\n";
        cout << "3: Sort by Memory Usage\n";
        cout << "4: Show Unsorted Processes\n";
        cout << "5: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.sortByName();
                p.showprocess();
                break;
            case 2:
                p.sortByPid();
                p.showprocess();
                break;
            case 3:
                p.sortByMemoryUsage();
                p.showprocess();
                break;
            case 4:
                p.printprocess();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}