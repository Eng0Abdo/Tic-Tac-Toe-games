#pragma once
#ifndef Tic_Tac_Toe
#define Tic_Tac_Toe

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int p1 = 0;
int p2 = 0;

template <typename T>
class sus_board : public Board<T> {
public:
    sus_board();
    ~sus_board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
    void declare_winner();
    bool check_sus(int x, int y, T symbol);
};

template <typename T>
class human_player : public Player<T> {
public:
    human_player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class random_player : public RandomPlayer<T> {
public:
    random_player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
sus_board<T>::sus_board() {
    this->rows = 3;
    this->columns = 3;
    this->board = new T * [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]{};
    }
    this->n_moves = 0;
}

template <typename T>
sus_board<T>::~sus_board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool sus_board<T>::update_board(int x, int y, T symbol) {
    if (this->board[x][y] != 0) {
        return false;
    }
    this->board[x][y] = symbol;
    this->n_moves++;
    if (check_sus(x, y, symbol)) {
        if (this->n_moves % 2 == 0) {
            p2++;
        }
        else {
            p1++;
        }
    }
    return true;
}

template <typename T>
void sus_board<T>::display_board() {
    cout << "\n--------------------------------\n";
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) {
                cout << setw(8) << "( " + to_string(i) + "," + to_string(j) + " )" << " |";
            }
            else {
                cout << setw(8) << static_cast<char>(this->board[i][j]) << " |";
            }
        }
        cout << "\n--------------------------------\n";
    }
    cout << endl;
    cout << "score player1 : " << p1 << endl;
    cout << "score player2 : " << p2 << endl;
}

template <typename T>
bool sus_board<T>::check_sus(int x, int y, T symbol) {
    if (y >= 0 && y <= 2 && this->board[x][0] == 'S' && this->board[x][1] == 'U' && this->board[x][2] == 'S') {
        return true;
    }
    if (x >= 0 && x <= 2 && this->board[0][y] == 'S' && this->board[1][y] == 'U' && this->board[2][y] == 'S') {
        return true;
    }
    if (x == y && this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
        return true;
    }
    if (x + y == 2 && this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S') {
        return true;
    }
    return false;
}

template <typename T>
bool sus_board<T>::is_win() {
    return game_is_over() && (p1 > p2 || p1 < p2);
}

template <typename T>
bool sus_board<T>::is_draw() {
    return (p1 == p2) && game_is_over();
}

template <typename T>
bool sus_board<T>::game_is_over() {
    return this->n_moves == (this->rows * this->columns);
}

template <typename T>
void sus_board<T>::declare_winner() {
    if (game_is_over()) {
        if (p1 > p2) {
            cout << "Player 1 wins with " << p1 << " points!" << endl;
        }
        else if (p2 > p1) {
            cout << "Player 2 wins with " << p2 << " points!" << endl;
        }
        else {
            cout << "It's a draw! Both players have " << p1 << " points." << endl;
        }
    }
}

template <typename T>
human_player<T>::human_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void human_player<T>::getmove(int& x, int& y) {
    do {
        cout << this->name << ", enter row (0-2): ";
        cin >> x;
        cout << this->name << ", enter column (0-2): ";
        cin >> y;
        if (y < 0 || y > 2 || x < 0 || x > 2) {
            cout << "Invalid input. Try again.\n";
        }
    } while (y < 0 || y > 2 || x < 0 || x > 2);
}

template <typename T>
random_player<T>::random_player(string name, T symbol) : RandomPlayer<T>(symbol) {
    this->name = name;
}

template <typename T>
void random_player<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 3;
}

#endif
