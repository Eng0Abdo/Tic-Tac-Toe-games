#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Universe {
private:
    string grid[20][20];  // 2D array representing the universe grid

public:
    // Initialize the grid with "-" representing dead cells
    void initialize() {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                grid[i][j] = "-";  // Set all cells to be dead initially
            }
        }
    }

    // Reset and display the current grid
    void reset() {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                cout << setw(4) << grid[i][j];  // Print each cell with a width of 4
            }
            cout << endl;  // Move to the next line after each row
        }
    }

    // Mark a cell as "X" based on its index number (0 to 399)
    void markCell(int number) {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (i * 20 + j == number) {  // Check if the number matches the current cell's index
                    grid[i][j] = "X";  // Mark the cell as alive
                    cout << "Cell marked with X." << endl;
                    return;
                }
            }
        }
        cout << "Invalid number. Please try again." << endl;  // If the number is out of range
    }

    // Count the number of neighboring cells that are alive ("X")
    int count_neighbors(int x, int y) {
        int neighbors = 0;

        // Check all 8 directions around the current cell
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;  // Skip the current cell itself

                int ni = x + i;  // New row for neighbor
                int nj = y + j;  // New column for neighbor

                // Check if the neighbor is within bounds of the grid
                if (ni >= 0 && ni < 20 && nj >= 0 && nj < 20) {
                    if (grid[ni][nj] == "X") {  // If the neighbor is alive
                        neighbors++;
                    }
                }
            }
        }

        return neighbors;  // Return the total number of alive neighbors
    }

    // Calculate the next generation of cells based on Conway's Game of Life rules
    void next_generation() {
        string newGrid[20][20];  // Temporary grid to hold the next generation's state

        // Loop through each cell to determine its next state
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                int neighbors = count_neighbors(i, j);  // Get the number of alive neighbors

                // If the cell is alive ("X")
                if (grid[i][j] == "X") {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = "-";  // Cell dies if it has less than 2 or more than 3 neighbors
                    } else {
                        newGrid[i][j] = "X";  // Cell stays alive if it has 2 or 3 neighbors
                    }
                } else {  // If the cell is dead ("-")
                    if (neighbors == 3) {
                        newGrid[i][j] = "X";  // Cell becomes alive if it has exactly 3 neighbors
                    } else {
                        newGrid[i][j] = "-";  // Cell stays dead if it doesn't have 3 neighbors
                    }
                }
            }
        }

        // Copy the new grid's state back to the original grid
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }

    // Display the current state of the grid
    void display() {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                cout << setw(4) << grid[i][j];  // Print each cell with a width of 4
            }
            cout << endl;  // Move to the next line after each row
        }
    }

    // Main function to run the game, allowing user interaction
    void run() {
        int choice;
        int inputNumber;
        int numGenerations;

        while (true) {
            // Display menu options
            cout << "\nChoose an option:\n";
            cout << "1. Mark a cell\n";
            cout << "2. Generate next generations\n";
            cout << "3. Reset the game\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    display();  // Show the current grid before marking a cell
                    cout << "Enter a cell number to mark(from 0 to 399): ";
                    cin >> inputNumber;
                    markCell(inputNumber);  // Mark the specified cell
                    display();  // Show the grid after marking the cell
                    break;
                case 2:
                    cout << "Enter the number of generations to generate: ";
                    cin >> numGenerations;
                    for (int i = 0; i < numGenerations; ++i) {
                        cout << "\nGeneration " << (i + 1) << ":\n";  // Display generation number
                        next_generation();  // Calculate the next generation
                        display();  // Show the grid after updating
                    }
                    break;
                case 3:
                    initialize();  // Reset the grid to its initial state
                    display();  // Show the grid after resetting
                    break;
                case 4:
                    cout << "Exiting the program. Goodbye!" << endl;
                    return;  // Exit the program
                default:
                    cout << "Invalid choice. Please try again.\n";  // Invalid input handling
            }
        }
    }
};

int main() {
    Universe universe;
    universe.initialize();  // Initialize the grid

    universe.run();  // Run the game and allow user interaction

    return 0;  // Return 0 to indicate successful program execution
}
