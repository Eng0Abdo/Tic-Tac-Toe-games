
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
class CONNECT4_human_player : public Player<T> {
public:
 CONNECT4_human_player(string name, T symbol);
 void getmove(int& x, int& y) override;
};

template <typename T>
class CONNECT4_random_player : public RandomPlayer<T> {
public:
    CONNECT4_random_player(string name, T symbol);
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
CONNECT4_human_player<T>::CONNECT4_human_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void CONNECT4_human_player<T>::getmove(int& x, int& y) {
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
CONNECT4_random_player<T>::CONNECT4_random_player(string name, T symbol) : RandomPlayer<T>(symbol) {
    this->name = name+ "(Random Player)";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void CONNECT4_random_player<T>::getmove(int& x, int& y) {
    y = rand() % 7;  // set random column
    x = 9; // not used
}

#endif




// main
//void game2() {

   // while (true)
   //  {
    //    string choice;
      //  Player<char>* players[2];
       // CONNECT4_BOARD<char>* theBoard = new CONNECT4_BOARD<char>();
       // string player1Name, player2Name;

       // cout << "Welcome to CONNECT 4 Game." << endl;

      //  cout << "Enter Player 1 name: ";
       // cin >> player1Name;


       // while (true)
        //{
         //   cout << "Choose Player 1 type:\n";
          //  cout << "1. Human\n";
          //  cout << "2. Random Computer\n";
           // cin >> choice;

         //   if (choice == "1") {
          //      players[0] = new CONNECT4_human_player<char>(player1Name, 'X');
           //     break;
           // }
           // else if (choice == "2") {
            //    players[0] = new CONNECT4_random_player<char>(player1Name,'X');
              //  break;
           // }
          //  else {
               // cout << "please enter a valid choice" << endl;
          //  }

       // }


       // cout << "Enter Player 2 name: ";
       // cin >> player2Name;

       // while (true)
       // {
         //   cout << "Choose Player 2 type:\n";
          //  cout << "1. Human\n";
           // cout << "2. Random Computer\n";
          //  cin >> choice;

          //  if (choice == "1") {
           //     players[1] = new CONNECT4_human_player<char>(player2Name, 'O');
            //    break;
          //  }
           // else if (choice == "2") {
            //    players[1] = new CONNECT4_random_player<char>(player2Name,'O');
             //   break;
           // }
           // else {
           //     cout << "please enter a valid choice" << endl;
           // }

        //}

        //GameManager<char> connect4game(theBoard, players);
        //connect4game.run();

       // delete theBoard;
       // for (int i = 0; i < 2; ++i) {
        //    delete players[i];
      //  }

       // cout << "Your game is finished do you want to continue ?" << endl;
       // cout << "[1] YES" << endl;
       // cout << "[2] NO" << endl;
       // string exit;
        //while (true)
       // {
         //   cin >> exit;
         //   if (exit == "1") {
          //      break;
           // }
          //  else if (exit == "2") {
          //      break;
         //   }
         //   else {
            //    cout << "please enter a valid option" << endl;
              //  cout << "[1] YES" << endl;
              //  cout << "[2] NO" << endl;
           // }

       // }

       // if (exit == "1") {
         //   continue;
       // }
       // else if (exit == "2") {
       //     break;
      //  }
   // }

//}
