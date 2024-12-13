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
        int position = 1; // Start numbering the positions

        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++) {
                if ((i == 0 && j == 2) || (i == 1 && (j >= 1 && j <= 3)) || (i == 2)) {
                    this->board[i][j] = '0' + position++; // Assign numbers as characters
                }
                else {
                    this->board[i][j] = ' '; // Empty space for non-playable areas
                }
            }
        }
        this->n_moves = 0;
    }

    bool update_board(int x, int y, T sympol) {
        if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) &&
            (this->board[x][y] >= '1' && this->board[x][y] <= '9')) {
            this->n_moves++;
            this->board[x][y] = sympol;
            return true;
        }
        return false;
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

            cout << this->name << " (" << this->symbol << "), enter where you want to play (1 to 9): ";
            cin >> position;

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
        this-> name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(nullptr))); // Initialize RNG
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



//void pyramid() {
    //    int choice;
    //    Player<char>* players[2];
    //    pyramid_X_O<char>* theBoard = new pyramid_X_O<char>();
    //    string player1Name, player2Name;
    //
    //    cout << "Welcome to Pyramid X-O Game. :)\n";
    //
    //    cout << "Enter Player 1 name: ";
    //    cin >> player1Name;
    //    cout << "Choose Player 1 type:\n";
    //    cout << "1. Human\n";
    //    cout << "2. Random Computer\n";
    //    cin >> choice;
    //
    //    switch (choice) {
    //    case 1:
    //        players[0] = new pyramid_X_O_Player<char>(player1Name, 'X');
    //        break;
    //    case 2:
    //        players[0] = new pyramid_X_O_Random_Player<char>('X');
    //        break;
    //    default:
    //        cout << "Invalid choice for Player 1. Exiting the game.\n";
    //        delete theBoard;
    //        pyramid();
    //    }
    //
    //    cout << "Enter Player 2 name: ";
    //    cin >> player2Name;
    //    cout << "Choose Player 2 type:\n";
    //    cout << "1. Human\n";
    //    cout << "2. Random Computer\n";
    //    cin >> choice;
    //
    //    switch (choice) {
    //    case 1:
    //        players[1] = new pyramid_X_O_Player<char>(player2Name, 'O');
    //        break;
    //    case 2:
    //        players[1] = new pyramid_X_O_Random_Player<char>('O');
    //        break;
    //    default:
    //        cout << "Invalid choice for Player 2. Exiting the game.\n";
    //        delete players[0];
    //        delete theBoard;
    //        pyramid();
    //    }
    //
    //    GameManager<char> pyramid_game(theBoard, players);
    //    pyramid_game.run();
    //
    //    delete theBoard;
    //    for (int i = 0; i < 2; ++i) {
    //        delete players[i];
    //    }
    //}