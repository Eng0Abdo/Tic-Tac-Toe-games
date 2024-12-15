#pragma once
#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

template <typename T>
class pyramid_X_O : public Board<T>{
public:
    pyramid_X_O() {
        this->rows = 3;
        this->columns = 5;
        this->board = new char* [this->rows];
        int position = 1;

        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++) {
                if ((i == 0 && j == 2) || (i == 1 && (j >= 1 && j <= 3)) || (i == 2)) {
                    this->board[i][j] = '0' + position++;
                }
                else {
                    this->board[i][j] = ' ';
                }
            }
        }
        this->n_moves = 0;
    }

    bool update_board(int x, int y, T sympol) {

        if ((x < 0 || x >= 3 || y < 0 || y >= 5) && (this->board[x][y] == 'X' || this->board[x][y] == 'O')) {
            return false;
        }

        string cellValue = "";
        cellValue += this->board[x][y];

        if (!isdigit(cellValue[0])) {
            return false;
        }

        int val = stoi(cellValue);
        if (val < 1 || val > 9) {
            return false;
        }

        this->board[x][y] = sympol;
        this->n_moves++;
        return true;
    }

    void display_board() {
        cout << "             | " << this-> board[0][2] << " |" << endl;
        cout << "         | " << this-> board[1][1] << " | " << this-> board[1][2] << " | " << this-> board[1][3] << " |   " << endl;
        cout << "     | " << this-> board[2][0] << " | " << this-> board[2][1] << " | " << this->board[2][2] << " | " << this->board[2][3] << " | " << this->board[2][4] << " | " << endl;
        cout << "================================" << endl;
    }
    bool is_win() {
        // Check column
        if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2]) {
            return true;
        }

        // Check rows
        if (this->board[1][1] != ' ' && this->board[1][1] == this->board[1][2] && this->board[1][1] == this->board[1][3]) {
            return true;
        }
        for (int i = 0; i < 3; i++) {
            if (this->board[2][i] != ' ' && this->board[2][i] == this->board[2][i + 1] && this->board[2][i] == this->board[2][i + 2]) {
                return true;
            }
        }

        // Check diagonals
        if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]) {
            return true;
        }
        if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4]) {
            return true;
        }

        return false;
    }
    bool is_draw() {
        return (this->n_moves == 9 && !is_win());
    }
    bool game_is_over() {
        return is_win() || is_draw();
    }
};

template <typename T>
class pyramid_X_O_Player : public Player<T> {
public:
    pyramid_X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int& x, int& y) {

        int position;
        string input;
        cout << this->name << " (" << this->symbol << "), enter where you want to play (1 to 9): ";
        while (true) {
            cin >> input;

            bool valid = true;
            for (char c : input) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Enter a valid option (1 to 9): ";
                continue;
            }

            position = stoi(input);

            if (position < 1 || position > 9) {
                cout << "Enter a valid option (1 to 9): ";
                continue;
            }

            break;
        }

            // Map position to board coordinates
            if (position == 1) {
                x = 0; y = 2; 
            }
            else if (position == 2) {
                x = 1; y = 1;
            }
            else if (position == 3) { 
                x = 1; y = 2;
            }
            else if (position == 4) { 
                x = 1; y = 3;
            }
            else if (position == 5) {
                x = 2; y = 0;
            }
            else if (position == 6) { 
                x = 2; y = 1;
            }
            else if (position == 7) { 
                x = 2; y = 2;
            }
            else if (position == 8) { 
                x = 2; y = 3;
            }
            else if (position == 9) { 
                x = 2; y = 4;
            }
            else {
                cout << "Invalid position. Please enter a number between 1 and 9.\n";
            }

    }
};

template <typename T>
class pyramid_X_O_Random_Player : public RandomPlayer<T> {
public:
    pyramid_X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
        this-> name = "Computer";
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void getmove(int& x, int& y) {
        int position = (rand() % 9) + 1;
        if (position == 1) { 
            x = 0; y = 2;
        }
        else if (position == 2) { 
            x = 1; y = 1; 
        }
        else if (position == 3) {
            x = 1; y = 2; 
        }
        else if (position == 4) { 
            x = 1; y = 3; 
        }
        else if (position == 5) { 
            x = 2; y = 0; 
        }
        else if (position == 6) { 
            x = 2; y = 1; 
        }
        else if (position == 7) { 
            x = 2; y = 2; 
        }
        else if (position == 8) { 
            x = 2; y = 3; 
        }
        else if (position == 9) { 
            x = 2; y = 4; 
        }
    }
};
