#ifndef UNTITLED26_GAME3_TicTacToe_H
#define UNTITLED26_GAME3_TicTacToe_H

#include "BoardGame_Classes.h"  // افتراض أن اسم الملف الأساسي BoardGame_Classes.h

int moves;
template <typename T>
class TicTacToe_Board : public Board<T> {
public:
    TicTacToe_Board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

template <typename T>
class Actual_Player : public Player<T> {
public:
    Actual_Player(string name, T symbol);
    Actual_Player(T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

//IMPLEMENTAION

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>
TicTacToe_Board<T>::TicTacToe_Board() {
    this->rows = this->columns = 5;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;

}

template<typename T>
bool TicTacToe_Board<T>::update_board(int x, int y, T mark) {
    if (this->n_moves >= 24) {
        this->n_moves = 25;
        moves = this->n_moves;
        return true;
    }
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}


template<typename T>
void TicTacToe_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-------------------------------------------------";
    }
    cout << endl;

}



template<typename T>
bool TicTacToe_Board<T>::is_win() {
    if (this->n_moves >= 24) {
        moves = this->n_moves;
        int O_counter = 0;
        int X_counter = 0;
        // فحص الصفوف
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns - 2; j++) {
                if (this->board[i][j] == this->board[i][j + 1] &&
                    this->board[i][j + 1] == this->board[i][j + 2] &&
                    this->board[i][j] != 0) {
                    if (this->board[i][j] == 'X') {
                        X_counter++;
                    }
                    else if (this->board[i][j] == 'O') {
                        O_counter++;
                    }
                }
            }
        }

        // فحص الأعمدة
        for (int j = 0; j < this->columns; j++) {
            for (int i = 0; i < this->rows - 2; i++) {
                if (this->board[i][j] == this->board[i + 1][j] &&
                    this->board[i + 1][j] == this->board[i + 2][j] &&
                    this->board[i][j] != 0) {
                    if (this->board[i][j] == 'X') {
                        X_counter++;
                    }
                    else if (this->board[i][j] == 'O') {
                        O_counter++;
                    }
                }
            }
        }

        // فحص القطر الرئيسي (main diagonal)
        for (int i = 0; i < this->rows - 2; i++) {
            for (int j = 0; j < this->columns - 2; j++) {
                if (this->board[i][j] == this->board[i + 1][j + 1] &&
                    this->board[i + 1][j + 1] == this->board[i + 2][j + 2] &&
                    this->board[i][j] != 0) {
                    if (this->board[i][j] == 'X') {
                        X_counter++;
                    }
                    else if (this->board[i][j] == 'O') {
                        O_counter++;
                    }
                }
            }
        }

        // فحص القطر العكسي (anti-diagonal)
        for (int i = 0; i < this->rows - 2; i++) {
            for (int j = 2; j < this->columns; j++) {
                if (this->board[i][j] == this->board[i + 1][j - 1] &&
                    this->board[i + 1][j - 1] == this->board[i + 2][j - 2] &&
                    this->board[i][j] != 0) {
                    if (this->board[i][j] == 'X') {
                        X_counter++;
                    }
                    else if (this->board[i][j] == 'O') {
                        O_counter++;
                    }
                }
            }
        }
        if (this->n_moves == 24) {
            moves = this->n_moves;
            if (O_counter > X_counter) return true;
            return false;
        }
        if (this->n_moves == 25) {
            moves = this->n_moves;
            if (X_counter > O_counter) return true;
            return false;
        }
    }return false;


}
template<typename T>
bool TicTacToe_Board<T>::is_draw() {
    return (this->n_moves == 25 && !is_win());
}

template<typename T>
bool TicTacToe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}


template<typename T>
Actual_Player<T>::Actual_Player(string name, T symbol) : Player<T>(name, symbol)
{
}

template<typename T>
void Actual_Player<T>::getmove(int& x, int& y) {
    if (moves >= 24) return;
    cout << this->name << ", enter row (0-2): ";
    cin >> x;
    cout << this->name << ", enter column (0-2): ";
    cin >> y;
}

template<typename T>
X_O_Random_Player<T>::X_O_Random_Player(string name, T symbol) : RandomPlayer<T>(symbol) {

    this->dimension = 5;
    this->name = name + " (Random Computer Player)";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

}

template<typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    if (moves >= 25) return;
    x = rand() % 5;
    y = rand() % 5;

}
#endif