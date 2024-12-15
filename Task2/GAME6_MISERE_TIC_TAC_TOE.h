
#include "BoardGame_Classes.h"  // Assuming the main header file is named BoardGame_Classes.h

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Template class for the Misere Tic-Tac-Toe board
template <typename T>
class Misere_TicTacToe_board : public Board<T> {
public:
    Misere_TicTacToe_board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

// Template class for an actual human player
template <typename T>
class Misere_TicTacToe_Player : public Player<T> {
public:
    Misere_TicTacToe_Player(string name, T symbol);
    Misere_TicTacToe_Player(T symbol);
    void getmove(int& x, int& y) override;
};

// Template class for a smart AI player
template <typename T>
class Misere_TicTacToe_Random_Player : public RandomPlayer<T> {
public:
    Misere_TicTacToe_Random_Player(string name,T symbol);
    void getmove(int& x, int& y) override;
};

//--------------------------------------- IMPLEMENTATION

template <typename T>
Misere_TicTacToe_board<T>::Misere_TicTacToe_board() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Misere_TicTacToe_board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
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

template <typename T>
void Misere_TicTacToe_board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << (this->board[i][j] ? this->board[i][j] : ' ') << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool Misere_TicTacToe_board<T>::is_win() {
    // check rows and cols

    // check rows
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] == this->board[i][1] &&
            this->board[i][1] == this->board[i][2] &&
            this->board[i][0] != 0) {
            return true;
        }
    }

// Check columns
    for (int j = 0; j < this->columns; j++) {
        if (this->board[0][j] == this->board[1][j] &&
            this->board[1][j] == this->board[2][j] &&
            this->board[0][j] != 0) {
            return true;
        }
    }

    // check diagonals
    if ((this->board[0][0] == this->board[1][1] &&
         this->board[1][1] == this->board[2][2] &&
         this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] &&
         this->board[1][1] == this->board[2][0] &&
         this->board[0][2] != 0)) {
        return true;
    }

    return false;
}


template <typename T>
bool Misere_TicTacToe_board<T>::is_draw() {
    return (this->n_moves == this->rows * this->columns && !is_win());
}

template <typename T>
bool Misere_TicTacToe_board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
Misere_TicTacToe_Player<T>::Misere_TicTacToe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
Misere_TicTacToe_Player<T>::Misere_TicTacToe_Player(T symbol) : Player<T>("Player", symbol) {}

template <typename T>
void Misere_TicTacToe_Player<T>::getmove(int &x, int &y) {
    cout << " please ,enter row (0-2): ";
    cin >> x;
    cout <<  " please ,enter column (0-2): ";
    cin >> y;
}

template <typename T>
Misere_TicTacToe_Random_Player<T>::Misere_TicTacToe_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name + " (Random Computer Player)";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

template <typename T>
void Misere_TicTacToe_Random_Player<T>::getmove(int &x, int &y) {
    x = rand() % 3;
    y = rand() % 3;
}




