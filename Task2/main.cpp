#include <iostream>
#include "BoardGame_Classes.h"
#include "pyramid_X_O.h"
#include "sus.h"
#include "word tic-tac-toe.h"
#include "gaint x_o.h"
#include "GAME6_MISERE_TIC_TAC_TOE.h"
#include "Game3_TicTacToe.h"
#include "Numerical_Tic_Tac_Toe.h"
#include "CONNECT_FOUR_H.h"



using namespace std;



void pyramid() {

    while (true)
    {
        string choice;
        Player<char>* players[2];
        pyramid_X_O<char>* theBoard = new pyramid_X_O<char>();
        string player1Name, player2Name;

        cout << "Welcome to Pyramid Tic-Tac-Toe game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;

        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new pyramid_X_O_Player<char>(player1Name, 'X');
                break;
            }
            else if (choice == "2") {
                players[0] = new pyramid_X_O_Random_Player<char>('X');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new pyramid_X_O_Player<char>(player2Name, 'O');
                break;
            }
            else if (choice == "2") {
                players[1] = new pyramid_X_O_Random_Player<char>('O');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<char> pyramidGame(theBoard, players);
        pyramidGame.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }
}


void game2() {

    while (true)
     {
        string choice;
        Player<char>* players[2];
        CONNECT4_BOARD<char>* theBoard = new CONNECT4_BOARD<char>();
        string player1Name, player2Name;

        cout << "Welcome to CONNECT 4 Game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;


        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new CONNECT4_human_player<char>(player1Name, 'X');
                break;
            }
            else if (choice == "2") {
                players[0] = new CONNECT4_random_player<char>(player1Name,'X');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new CONNECT4_human_player<char>(player2Name, 'O');
                break;
            }
            else if (choice == "2") {
                players[1] = new CONNECT4_random_player<char>(player2Name,'O');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<char> connect4game(theBoard, players);
        connect4game.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }

}

 void Game3() {

     while (true)
     {
         string choice;
         Player<char>* players[2];
         TicTacToe_Board<char>* T = new TicTacToe_Board<char>();
         string player1Name, player2Name;

         cout << "Welcome to 5*5 Tic-Tac-Toe game." << endl;

         cout << "Enter Player 1 name: ";
         cin >> player1Name;

         while (true)
         {
             cout << "Choose Player 1 type:\n";
             cout << "1. Human\n";
             cout << "2. Random Computer\n";
             cin >> choice;

             if (choice == "1") {
                 players[0] = new TicTacToe_Player<char>(player1Name, 'X');
                 break;
             }
             else if (choice == "2") {
                 players[0] = new TicTacToe_Random_Player<char>(player1Name,'X');
                 break;
             }
             else {
                 cout << "please enter a valid choice" << endl;
             }

         }


         cout << "Enter Player 2 name: ";
         cin >> player2Name;

         while (true)
         {
             cout << "Choose Player 2 type:\n";
             cout << "1. Human\n";
             cout << "2. Random Computer\n";
             cin >> choice;

             if (choice == "1") {
                 players[1] = new TicTacToe_Player<char>(player2Name, 'O');
                 break;
             }
             else if (choice == "2") {
                 players[1] = new TicTacToe_Random_Player<char>(player2Name,'O');
                 break;
             }
             else {
                 cout << "please enter a valid choice" << endl;
             }

         }

         GameManager<char> x_o_game(T, players);
         x_o_game.run();

         delete T;
         for (int i = 0; i < 2; ++i) {
             delete players[i];
         }

         cout << "Your game is finished do you want to continue ?" << endl;
         cout << "[1] YES" << endl;
         cout << "[2] NO" << endl;
         string exit;
         while (true)
         {
             cin >> exit;
             if (exit == "1") {
                 break;
             }
             else if (exit == "2") {
                 break;
             }
             else {
                 cout << "please enter a valid option" << endl;
                 cout << "[1] YES" << endl;
                 cout << "[2] NO" << endl;
             }

         }

         if (exit == "1") {
             continue;
         }
         else if (exit == "2") {
             break;
         }
     }
 }

void wordTicTac() {
    while (true)
    {
        string choice;
        Player<char>* players[2];
        wordBoard<char>* theBoard = new wordBoard<char>();
        string player1Name, player2Name;

        cout << "Welcome to Word Tic Tac Toe Game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;

        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new wordPlayer<char>(player1Name);
                break;
            }
            else if (choice == "2") {
                players[0] = new wordRandomPlayer<char>();
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new wordPlayer<char>(player2Name);
                break;
            }
            else if (choice == "2") {
                players[1] = new wordRandomPlayer<char>();
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<char> wordGame(theBoard, players);
        wordGame.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }
}

void game5() {
    while (true)
    {
        string choice;
        Player<char>* players[2];
        tic_tac_board<char>* theBoard = new tic_tac_board<char>();
        string player1Name, player2Name;

        cout << "Welcome to numerical_tic_tac Game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;

        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new tic_tac_human_player<char>(player1Name, 2);
                break;
            }
            else if (choice == "2") {
                players[0] = new tic_tac_random_player<char>(player1Name,3);
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new tic_tac_human_player<char>(player2Name, 1);
                break;
            }
            else if (choice == "2") {
                players[1] = new tic_tac_random_player<char>(player2Name,4);
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<char> num_tic_tac_Game(theBoard, players);
        num_tic_tac_Game.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }
}

 void Game6() {
     while (true) {
         string choice1;
         string choice2;
         Player<char>* players[2];
         Misere_TicTacToe_board<char>* M = new Misere_TicTacToe_board<char>();
         string player1Name, player2Name;

         cout << "Welcome to Misere Tic Tac Toe." << endl;

         cout << "Enter Player 1 name: ";
         cin >> player1Name;

         cout << "Enter Player 2 name: ";
         cin >> player2Name;

         while (true) {

             cout << "Choose Player 1 type:\n";
             cout << "1. Human\n";
             cout << "2. Random Computer\n";
             cin >> choice1;

             if (choice1 == "1") {
                 players[0] = new Misere_TicTacToe_Player<char>(player2Name, 'X');
                 break;
             } else if (choice1 == "2") {
                 players[0] = new Misere_TicTacToe_Random_Player<char>(player2Name, 'X');
                 break;
             } else {
                 cout << "Please enter a valid choice." << endl;
             }
         }


         while (true) {

             cout << "Choose Player 2 type:\n";
             cout << "1. Human\n";
             cout << "2. Random Computer\n";
             cin >> choice2;

             if (choice2 == "1") {
                 players[1] = new Misere_TicTacToe_Player<char>(player1Name, 'O');
                 break;
             } else if (choice2 == "2") {
                 players[1] = new Misere_TicTacToe_Random_Player<char>(player1Name, 'O');
                 break;
             } else {
                 cout << "Please enter a valid choice." << endl;
             }
         }


         GameManager<char> x_o_game(M, players);
         x_o_game.run();


         delete M;
         for (int i = 0; i < 2; ++i) {
             delete players[i];
         }

         cout << "Your game is finished. Do you want to continue?" << endl;
         cout << "[1] YES" << endl;
         cout << "[2] NO" << endl;

         string exitChoice;
         while (true) {
             cin >> exitChoice;
             if (exitChoice == "1") {
                 break;
             } else if (exitChoice == "2") {
                 break;
             } else {
                 cout << "Please enter a valid option:" << endl;
                 cout << "[1] YES" << endl;
                 cout << "[2] NO" << endl;
             }
         }
         if(exitChoice=="1"){
             continue;
         }
         else if(exitChoice == "2"){
             break;
         }
     }
 }

void giant() {
    while (true)
    {
        string choice;
        Player<string>* players[2];
        giantXOboard<string>* theBoard = new giantXOboard<string>();
        string player1Name, player2Name;

        cout << "Welcome to Ultimate Tic Tac Toe game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;

        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new giantXOplayer<string>(player1Name, "X");
                break;
            }
            else if (choice == "2") {
                players[0] = new giantXOrandomPlayer<string>("X");
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new giantXOplayer<string>(player2Name, "O");
                break;
            }
            else if (choice == "2") {
                players[1] = new giantXOrandomPlayer<string>("O");
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<string> giantGame(theBoard, players);
        giantGame.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }
}

void GAME8() {

    while (true)
    {
        string choice;
        Player<char>* players[2];
        sus_board<char>* theBoard = new sus_board<char>();
        string player1Name, player2Name;

        cout << "Welcome to SUS Game." << endl;

        cout << "Enter Player 1 name: ";
        cin >> player1Name;

        while (true)
        {
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[0] = new human_player<char>(player1Name, 'S');
                break;
            }
            else if (choice == "2") {
                players[0] = new random_player<char>(player1Name, 'S');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }


        cout << "Enter Player 2 name: ";
        cin >> player2Name;

        while (true)
        {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == "1") {
                players[1] = new human_player<char>(player2Name, 'U');
                break;
            }
            else if (choice == "2") {
                players[1] = new random_player<char>(player2Name, 'U');
                break;
            }
            else {
                cout << "please enter a valid choice" << endl;
            }

        }

        GameManager<char> SUSGAME(theBoard, players);
        SUSGAME.run();

        delete theBoard;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

        cout << "Your game is finished do you want to continue ?" << endl;
        cout << "[1] YES" << endl;
        cout << "[2] NO" << endl;
        string exit;
        while (true)
        {
            cin >> exit;
            if (exit == "1") {
                break;
            }
            else if (exit == "2") {
                break;
            }
            else {
                cout << "please enter a valid option" << endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
            }

        }

        if (exit == "1") {
            continue;
        }
        else if (exit == "2") {
            break;
        }
    }

}

int main() {
    cout << " Welcome to Tic Tac Toe Games" << endl;
    cout << "---------------------------------" << endl;

    while (true) {
        string choice;
        cout << " Enter Which game you want to play" << endl;
        cout << "---------------------------------" << endl;
        cout << " [1] : Pyramid Tic-Tac-Toe " << endl;
        cout << " [2] : Four-in-a-row " << endl;
        cout << " [3] : 5 x 5 Tic Tac Toe " << endl;
        cout << " [4] : Word Tic Tac Toe " << endl;
        cout << " [5] : Numerical Tic-Tac-Toe " << endl;
        cout << " [6] : Misere Tic Tac Toe " << endl;
        cout << " [7] : Ultimate Tic Tac Toe " << endl;
        cout << " [8] : SUS " << endl;
        cout << " [0] : Exit." << endl;
        cin >> choice;

        if (choice == "0") {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else if (choice == "1") {
            pyramid();
        }
        else if (choice == "2") {
            game2();
        }
        else if (choice == "3") {
            Game3();
        }
        else if (choice == "4") {
            wordTicTac();
        }
        else if (choice == "5") {
            game5();
        }
        else if (choice == "6") {
            Game6();
        }
        else if (choice == "7") {
            giant();
        }
        else if (choice == "8") {
            GAME8();
        }
        else {
            cout << "please enter a valid option" << endl;
        }
    }
    return 0;
}