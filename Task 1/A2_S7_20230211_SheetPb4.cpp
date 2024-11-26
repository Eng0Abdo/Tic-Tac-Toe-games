#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MySet {
private:
    vector<T> data;

    // Check if an item exists in the set
    bool exist(const T& item) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == item) {
                return true;
            }
        }
        return false;
    }

    // Get the index of an item in the set
    int getIndex(const T& item) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == item) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

public:
    // Add an item to the set
    void add(const T& item) {
        if (!exist(item)) {
            data.push_back(item);
        }
    }

    // Remove an item from the set
    void remove(const T& item) {
        int index = getIndex(item);
        if (index != -1) {
            data.erase(data.begin() + index);
        }
    }

    // Get the size of the set
    int size() {
        return static_cast<int>(data.size());
    }

    // Check if an item exists in the set
    bool isexist(const T& item) {
        return exist(item);
    }

    // Return a dynamically allocated array of set elements
    T* returnArray() const {
        T* array = new T[data.size()];
        for (size_t i = 0; i < data.size(); ++i) {
            array[i] = data[i];
        }
        return array;
    }

    // Print the elements of the set just for testing
    void print() const {
        for (const T& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test with integers
    cout << "===================================================\n";
    cout << "Testing with integers:" << endl;
    MySet<int> intSet;
    intSet.add(5);
    intSet.add(3);
    intSet.add(7);
    intSet.add(3); // should not be added
    intSet.print(); // Expected output: 5 3 7
    intSet.remove(3);
    intSet.print(); // Expected output: 5 7
    cout << "Size: " << intSet.size() << endl; // Expected: 2
    cout << "Contains 7: " << (intSet.isexist(7) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Contains 10: " << (intSet.isexist(10) ? "Yes" : "No") << endl; // Expected: No
    cout << "===================================================\n";

    // Test with doubles
    cout << "Testing with doubles:" << endl;
    MySet<double> doubleSet;
    doubleSet.add(5.5);
    doubleSet.add(3.3);
    doubleSet.add(7.7);
    doubleSet.add(3.3); // should not be added
    doubleSet.print(); // Expected output: 5.5 3.3 7.7
    doubleSet.remove(3.3);
    doubleSet.print(); // Expected output: 5.5 7.7
    cout << "Size: " << doubleSet.size() << endl; // Expected: 2
    cout << "Contains 5.5: " << (doubleSet.isexist(5.5) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Contains 3.3: " << (doubleSet.isexist(3.3) ? "Yes" : "No") << endl; // Expected: No
    cout << "===================================================\n";
    // Test with characters
    cout << "Testing with characters:" << endl;
    MySet<char> charSet;
    charSet.add('a');
    charSet.add('b');
    charSet.add('c');
    charSet.add('a'); // should not be added
    charSet.print(); // Expected output: a b c
    charSet.remove('b');
    charSet.print(); // Expected output: a c
    cout << "Size: " << charSet.size() << endl; // Expected: 2
    cout << "Contains 'a': " << (charSet.isexist('a') ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Contains 'z': " << (charSet.isexist('z') ? "Yes" : "No") << endl; // Expected: No
    cout << "===================================================\n";

    // Test with strings
    cout << "Testing with strings:" << endl;
    MySet<string> stringSet;
    stringSet.add("Abdelrahman");
    stringSet.add("Emad");
    stringSet.add("Mahmoud");
    stringSet.add("Mahmoud"); // should not be added
    stringSet.print(); // Expected output: Abdelrahman Emad Mahmoud
    stringSet.remove("Mahmoud");
    stringSet.print(); // Expected output: Abdelrahman Emad
    cout << "Size: " << stringSet.size() << endl; // Expected: 2
    cout << "Contains 'Abdelrahman': " << (stringSet.isexist("Abdelrahman") ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Contains 'Mohamed': " << (stringSet.isexist("Mohamed") ? "Yes" : "No") << endl; // Expected: No
    cout << "===================================================\n";

    return 0;
}

