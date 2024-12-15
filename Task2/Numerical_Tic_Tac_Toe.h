
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

vector<int> evennum = {2, 4, 6, 8};
vector<int> unevennum; // for used even number
vector<int> unodd;  // for used odd number
vector<int> oddnum = {1, 3,5, 7, 9};

// tic_tac_board
template <typename T>
class tic_tac_board : public Board<T> {
public:
    tic_tac_board();
    ~tic_tac_board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

private:
    int random_number(bool is_even);
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
tic_tac_board<T>::tic_tac_board() {
    this->rows = 3;
    this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]{};
    }
    this->n_moves = 0;
}

template <typename T>
tic_tac_board<T>::~tic_tac_board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}




template <typename T>
bool tic_tac_board<T>::update_board(int x, int y, T symbol) {
    int num;
int p=symbol;


    if (this->board[x][y] != 0) {
        if(p==1||p==2){
        cout << "Cell already occupied, try again.\n";}
        return false;
    }

    while (true) {
        if (symbol == 1) { // human Player 2
            cout << "Enter an even number (2, 4, 6, 8): ";
            cin >> num;
            
            if (find(evennum.begin(), evennum.end(), num) != evennum.end() &&
                find(unevennum.begin(), unevennum.end(), num) == unevennum.end()) {
                
                this->board[x][y] = num;
                unevennum.push_back(num);
                this->n_moves++;
                return true;
            }
            cout << "invalid even number, try again.\n";

        } else if (symbol == 2) { //  human Player 1
            cout << "enter an odd number (1, 3,5, 7, 9): ";
            cin >> num;
            
            if (find(oddnum.begin(), oddnum.end(), num) != oddnum.end() &&
                find(unodd.begin(), unodd.end(), num) == unodd.end()) {
                
                this->board[x][y] = num;
                unodd.push_back(num); 
                this->n_moves++;
                return true;
            }
            cout << "invalid odd number, try again.\n";

        } else if (symbol == 3) { // Random odd player 1
            num = random_number(false); //  random odd number
            if (find(unodd.begin(), unodd.end(), num) == unodd.end()) {
            
                this->board[x][y] = num;
                unodd.push_back(num); 
                this->n_moves++;
                return true;
            }

        } else if (symbol == 4) { // Random even player 2
            num = random_number(true); //  random even number
            if (find(unevennum.begin(), unevennum.end(), num) == unevennum.end()) {
                
                this->board[x][y] = num;
                unevennum.push_back(num); 
                this->n_moves++;
                return true;
            }
        }
    }

    
    return false;
}

template <typename T>
int tic_tac_board<T>::random_number(bool is_even) {// take even or odd numer for random player
    if(is_even)  {
    return (2 * ((rand() % 4) + 1)); } // even number
    return (2 * (rand() % 5) + 1);  // odd number
}

template <typename T>
void tic_tac_board<T>::display_board() {
  
   
cout << "\n--------------------------------\n";

for (int i = 0; i < this->rows; i++) {
    cout << "| ";
    for (int j = 0; j < this->columns; j++) {
        if (this->board[i][j] == 0) { 
            cout << setw(8) << "( " + to_string(i) + "," + to_string(j) + " )" << " |";
        } else { 
            cout << setw(8) << static_cast<int>(this->board[i][j]) << " |";
        }
    }
    cout << "\n--------------------------------\n";
}
cout << endl;
}

template <typename T>
bool tic_tac_board<T>::is_win() {
    // check vertival
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0&&
            this->board[i][0] + this->board[i][1] + this->board[i][2] == 15) {
            return true;
        }
    }
    // check hotozinal
    for (int j = 0; j < this->columns; j++) {
        if (this->board[0][j] != 0 &&this->board[1][j] != 0 && this->board[2][j] != 0&&
            this->board[0][j] + this->board[1][j] + this->board[2][j] == 15) {
            return true;
        }
    }
    // check diagonal
    if (this->board[0][0] != 0 && this->board[1][1] != 0 &&this->board[2][2] != 0 &&
        this->board[0][0] + this->board[1][1] + this->board[2][2] == 15) {
        return true;
    }
    // check diagonal
    if (this->board[0][2] != 0 &&this->board[1][1] != 0 &&this->board[2][0] != 0 &&
        this->board[0][2] + this->board[1][1] + this->board[2][0] == 15) {
        return true;
    }
    return false;
}

template <typename T>
bool tic_tac_board<T>::is_draw() {
    return this->n_moves == (this->rows * this->columns) && !is_win();
}

template <typename T>
bool tic_tac_board<T>::game_is_over() {

    if( is_win() || is_draw()){
        return true;
    }
    else{
        return false;
    }
}

// player1
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
    this->name = name+"(random player)";
}

template <typename T>
void random_player<T>::getmove(int& x, int& y) {
    
    x = rand() % 3;  // take random row
    y = rand() % 3;// random column
 
    
}

#endif