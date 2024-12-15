
#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class CONNECT4_BOARD : public Board<T> {
public:
    CONNECT4_BOARD();
    ~CONNECT4_BOARD();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
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


template <typename T>// set board 6*7 for connect4
CONNECT4_BOARD<T>::CONNECT4_BOARD() {
    this->rows = 6;
    this->columns = 7;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]{};
    }
    this->n_moves = 0;
}

template <typename T>
CONNECT4_BOARD<T>::~CONNECT4_BOARD() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool CONNECT4_BOARD<T>::update_board(int x, int y, T symbol) {
    for (int i = this->rows - 1; i >= 0; i--) {
        if (this->board[i][y] == 0) {
            this->board[i][y] = symbol;
            this->n_moves++;
            return true;
        }
    }
    return false;
}

template <typename T>
void CONNECT4_BOARD<T>::display_board() {
    cout << "\n  ";
    for (int col = 0; col < this->columns; col++) {
        cout << col << "  ";
    }
    cout<<endl;
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) {
                cout << " " << " |";
            } else {
                cout << this->board[i][j] << " |";
            }
        }
   cout << endl;
    }
 cout << "------------------------\n";
    
}

template <typename T>
bool CONNECT4_BOARD<T>::is_win() {
    //check Horizontal
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 4; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    // check Vertical
    for (int i = 0; i <= this->rows - 4; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    // check Diagonal (top-left to bottom-right)
    for (int i = 0; i <= this->rows - 4; i++) {
        for (int j = 0; j <= this->columns - 4; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    //check  Diagonal (bottom-left to top-right)
    for (int i = 3; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 4; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2] &&
                this->board[i][j] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool CONNECT4_BOARD<T>::is_draw() {
    if (this->n_moves == (this->rows * this->columns) && !is_win()) {
        return true;
    }
    return false;
}

template <typename T>
bool CONNECT4_BOARD<T>::game_is_over() {
     if(is_win() || is_draw()){
        return true;
    }
     else{
        return false;
     }

}

// Implementation of player1
template <typename T>
human_player<T>::human_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void human_player<T>::getmove(int& x, int& y) {
    do {
        cout << this->name << ", enter column (0-6): ";
        cin >> y;
        if (y < 0 || y >= 7) {
            cout << "Invalid input. Try again.\n";
        }
    } while (y < 0 || y >= 7);
    x = 0; // not used
}

// Implementation of player2
template <typename T>
random_player<T>::random_player(string name, T symbol) : RandomPlayer<T>(symbol) {
    this->name = name+ "(Random Player)";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void random_player<T>::getmove(int& x, int& y) {
    y = rand() % 7;  // set random column
    x = 9; // not used
}

#endif
