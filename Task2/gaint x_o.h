#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "BoardGame_Classes.h"

using namespace std;

template <typename T>

class giantXOboard : public Board <T> {
private:
	string simpleXO[3][3] = {
		{"-", "-", "-"},
		{"-", "-", "-"},
		{"-", "-", "-"}
	};
	string winChar;
public:
	giantXOboard() {
		int position = 1;
		this->rows = 9;
		this->columns = 9;
		this->board = new string* [this->rows];
		for (int i = 0; i < 9; i++) {
			this->board[i] = new string[this->columns];
			for (int j = 0; j < 9; j++) {
				this->board[i][j] = to_string(position++);
			}
		}
		this->n_moves = 0;
	}

	void display_board() {
		for (int i = 0; i < 9; i++) {
			cout << endl;
			for (int j = 0; j < 9; j++) {
				cout << setw(4) << this->board[i][j] << " | ";
			}
			cout << endl << string(62, '_') << endl;
		}
	}

	bool update_board(int x, int y, T sympol) {
        int val = stoi(this->board[x][y]);
		if (!(x < 0 || x >= 9 || y < 0 || y >= 9) && (val >= 1 && val <= 81)) {
			this->n_moves++;
			this->board[x][y] = sympol;
			return true;
		}
		return false;
	}

	void fillBoard(int beginningRow, int beginningCol, string winningChar) {
		for (int i = beginningRow; i < beginningRow + 3; i++) {
			for (int j = beginningCol; j < beginningCol + 3; j++) {
				this->board[i][j] = winChar;
			}
		}
	}

    void smallWin() {
       
    // Check Board 1
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
                if (i == 0) {
                    winChar = this->board[0][0];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[1][0];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[2][0];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
            }
        }
        // Check cols
        for (int i = 0; i < 3; i++) {
            if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]) {
                if (i == 0) {
                    winChar = this->board[0][0];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[0][1];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[0][2];
                    simpleXO[0][0] = winChar;
                    fillBoard(0, 0, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) ||
            (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])) {
            winChar = this->board[1][1];
            simpleXO[0][0] = winChar;
            fillBoard(0, 0, winChar);
        }

    // Check Board 2
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5]) {
                if (i == 0) {
                    winChar = this->board[0][3];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[1][3];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[2][3];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
            }
        }
        // Check cols
        for (int i = 3; i < 6; i++) {
            if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]) {
                if (i == 3) {
                    winChar = this->board[0][3];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[0][4];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[0][5];
                    simpleXO[0][1] = winChar;
                    fillBoard(0, 3, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[0][3] == this->board[1][4] && this->board[1][4] == this->board[2][5]) ||
            (this->board[0][5] == this->board[1][4] && this->board[1][4] == this->board[2][3])) {
            winChar = this->board[1][4];
            simpleXO[0][1] = winChar;
            fillBoard(0, 3, winChar);
        }

    // Check Board 3
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8]) {
                if (i == 0) {
                    winChar = this->board[0][6];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[1][6];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[2][6];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
            }
        }
        // Check cols
        for (int i = 6; i < 9; i++) {
            if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]) {
                if (i == 6) {
                    winChar = this->board[0][6];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[0][7];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[0][8];
                    simpleXO[0][2] = winChar;
                    fillBoard(0, 6, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[0][6] == this->board[1][7] && this->board[1][7] == this->board[2][8]) ||
            (this->board[0][8] == this->board[1][7] && this->board[1][7] == this->board[2][6])) {
            winChar = this->board[1][7];
            simpleXO[0][2] = winChar;
            fillBoard(0, 6, winChar);
        }

    // Check Board 4
        // Check rows
        for (int i = 3; i < 6; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
                if (i == 3) {
                    winChar = this->board[3][0];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[4][0];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[5][0];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
            }
        }
        // Check cols
        for (int i = 0; i < 3; i++) {
            if (this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i]) {
                if (i == 0) {
                    winChar = this->board[3][0];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[3][1];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[3][2];
                    simpleXO[1][0] = winChar;
                    fillBoard(3, 0, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[3][0] == this->board[4][1] && this->board[4][1] == this->board[5][2]) ||
            (this->board[3][2] == this->board[4][1] && this->board[4][1] == this->board[5][0])) {
            winChar = this->board[4][1];
            simpleXO[1][0] = winChar;
            fillBoard(3, 0, winChar);
        }

    // Check Board 5
        // Check rows
        for (int i = 3; i < 6; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5]) {
                if (i == 3) {
                    winChar = this->board[3][3];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[4][3];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[5][3];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
            }
        }
        // Check cols
        for (int i = 3; i < 6; i++) {
            if (this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i]) {
                if (i == 3) {
                    winChar = this->board[3][3];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[3][4];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[3][5];
                    simpleXO[1][1] = winChar;
                    fillBoard(3, 3, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[3][3] == this->board[4][4] && this->board[4][4] == this->board[5][5]) ||
            (this->board[3][5] == this->board[4][4] && this->board[4][4] == this->board[5][3])) {
            winChar = this->board[4][4];
            simpleXO[1][1] = winChar;
            fillBoard(3, 3, winChar);
        }

    // Check Board 6
        // Check rows
        for (int i = 3; i < 6; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8]) {
                if (i == 3) {
                    winChar = this->board[3][6];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[4][6];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[5][6];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
            }
        }
        // Check cols
        for (int i = 6; i < 9; i++) {
            if (this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i]) {
                if (i == 6) {
                    winChar = this->board[3][6];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[3][7];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[3][8];
                    simpleXO[1][2] = winChar;
                    fillBoard(3, 6, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[3][6] == this->board[4][7] && this->board[4][7] == this->board[5][8]) ||
            (this->board[3][8] == this->board[4][7] && this->board[4][7] == this->board[5][6])) {
            winChar = this->board[4][7];
            simpleXO[1][2] = winChar;
            fillBoard(3, 6, winChar);
        }

        // Check Board 7
            // Check rows
        for (int i = 6; i < 9; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
                if (i == 6) {
                    winChar = this->board[6][0];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[7][0];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[8][0];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
            }
        }
        // Check cols
        for (int i = 0; i < 3; i++) {
            if (this->board[6][i] == this->board[7][i] && this->board[7][i] == this->board[8][i]) {
                if (i == 0) {
                    winChar = this->board[6][0];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
                else if (i == 1) {
                    winChar = this->board[6][1];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
                else if (i == 2) {
                    winChar = this->board[6][2];
                    simpleXO[2][0] = winChar;
                    fillBoard(6, 0, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[6][0] == this->board[7][1] && this->board[7][1] == this->board[8][2]) ||
            (this->board[6][2] == this->board[7][1] && this->board[7][1] == this->board[8][0])) {
            winChar = this->board[7][1];
            simpleXO[2][0] = winChar;
            fillBoard(6, 0, winChar);
        }

    // Check Board 8
        // Check rows
        for (int i = 6; i < 9; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5]) {
                if (i == 6) {
                    winChar = this->board[6][3];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[7][3];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[8][3];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
            }
        }
        // Check cols
        for (int i = 3; i < 6; i++) {
            if (this->board[6][i] == this->board[7][i] && this->board[7][i] == this->board[8][i]) {
                if (i == 3) {
                    winChar = this->board[6][3];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
                else if (i == 4) {
                    winChar = this->board[6][4];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
                else if (i == 5) {
                    winChar = this->board[6][5];
                    simpleXO[2][1] = winChar;
                    fillBoard(6, 3, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[6][3] == this->board[7][4] && this->board[7][4] == this->board[8][5]) ||
            (this->board[6][5] == this->board[7][4] && this->board[7][4] == this->board[8][3])) {
            winChar = this->board[7][4];
            simpleXO[2][1] = winChar;
            fillBoard(6, 3, winChar);
        }

    // Check Board 9
        // Check rows
        for (int i = 6; i < 9; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8]) {
                if (i == 6) {
                    winChar = this->board[6][6];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[7][6];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[8][6];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
            }
        }
        // Check cols
        for (int i = 6; i < 9; i++) {
            if (this->board[6][i] == this->board[7][i] && this->board[7][i] == this->board[8][i]) {
                if (i == 6) {
                    winChar = this->board[6][6];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
                else if (i == 7) {
                    winChar = this->board[6][7];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
                else if (i == 8) {
                    winChar = this->board[6][8];
                    simpleXO[2][2] = winChar;
                    fillBoard(6, 6, winChar);
                }
            }
        }
        // Check diagonals
        if ((this->board[6][6] == this->board[7][7] && this->board[7][7] == this->board[8][8]) ||
            (this->board[6][8] == this->board[7][7] && this->board[7][7] == this->board[8][6])) {
            winChar = this->board[7][7];
            simpleXO[2][2] = winChar;
            fillBoard(6, 6, winChar);
        }

    }


	bool is_win() {

        smallWin();

        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((simpleXO[i][0] == simpleXO[i][1] && simpleXO[i][1] == simpleXO[i][2] && simpleXO[i][0] != "-") ||
                (simpleXO[0][i] == simpleXO[1][i] && simpleXO[1][i] == simpleXO[2][i] && simpleXO[0][i] != "-")) {
                return true;
            }
        }

        // Check diagonals
        if ((simpleXO[0][0] == simpleXO[1][1] && simpleXO[1][1] == simpleXO[2][2] && simpleXO[0][0] != "-") ||
            (simpleXO[0][2] == simpleXO[1][1] && simpleXO[1][1] == simpleXO[2][0] && simpleXO[0][2] != "-")) {
            return true;
        }
        smallWin();
        return false;
	}

	bool is_draw() {
		return (this->n_moves == 81 && !is_win());
	}

	bool game_is_over() {
		return is_win() || is_draw();
	}


};

template <typename T>
class giantXOplayer : public Player<T> {
public:

    giantXOplayer(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int& x, int& y) {
        int position;

        cout << this->name << " (" << this->symbol << "), enter where you want to play (1 to 81): ";
        cin >> position;

        if (position == 1) { x = 0; y = 0; }
        else if (position == 2) { x = 0; y = 1; }
        else if (position == 3) { x = 0; y = 2; }
        else if (position == 4) { x = 0; y = 3; }
        else if (position == 5) { x = 0; y = 4; }
        else if (position == 6) { x = 0; y = 5; }
        else if (position == 7) { x = 0; y = 6; }
        else if (position == 8) { x = 0; y = 7; }
        else if (position == 9) { x = 0; y = 8; }

        else if (position == 10) { x = 1; y = 0; }
        else if (position == 11) { x = 1; y = 1; }
        else if (position == 12) { x = 1; y = 2; }
        else if (position == 13) { x = 1; y = 3; }
        else if (position == 14) { x = 1; y = 4; }
        else if (position == 15) { x = 1; y = 5; }
        else if (position == 16) { x = 1; y = 6; }
        else if (position == 17) { x = 1; y = 7; }
        else if (position == 18) { x = 1; y = 8; }

        else if (position == 19) { x = 2; y = 0; }
        else if (position == 20) { x = 2; y = 1; }
        else if (position == 21) { x = 2; y = 2; }
        else if (position == 22) { x = 2; y = 3; }
        else if (position == 23) { x = 2; y = 4; }
        else if (position == 24) { x = 2; y = 5; }
        else if (position == 25) { x = 2; y = 6; }
        else if (position == 26) { x = 2; y = 7; }
        else if (position == 27) { x = 2; y = 8; }

        else if (position == 28) { x = 3; y = 0; }
        else if (position == 29) { x = 3; y = 1; }
        else if (position == 30) { x = 3; y = 2; }
        else if (position == 31) { x = 3; y = 3; }
        else if (position == 32) { x = 3; y = 4; }
        else if (position == 33) { x = 3; y = 5; }
        else if (position == 34) { x = 3; y = 6; }
        else if (position == 35) { x = 3; y = 7; }
        else if (position == 36) { x = 3; y = 8; }

        else if (position == 37) { x = 4; y = 0; }
        else if (position == 38) { x = 4; y = 1; }
        else if (position == 39) { x = 4; y = 2; }
        else if (position == 40) { x = 4; y = 3; }
        else if (position == 41) { x = 4; y = 4; }
        else if (position == 42) { x = 4; y = 5; }
        else if (position == 43) { x = 4; y = 6; }
        else if (position == 44) { x = 4; y = 7; }
        else if (position == 45) { x = 4; y = 8; }

        else if (position == 46) { x = 5; y = 0; }
        else if (position == 47) { x = 5; y = 1; }
        else if (position == 48) { x = 5; y = 2; }
        else if (position == 49) { x = 5; y = 3; }
        else if (position == 50) { x = 5; y = 4; }
        else if (position == 51) { x = 5; y = 5; }
        else if (position == 52) { x = 5; y = 6; }
        else if (position == 53) { x = 5; y = 7; }
        else if (position == 54) { x = 5; y = 8; }

        else if (position == 55) { x = 6; y = 0; }
        else if (position == 56) { x = 6; y = 1; }
        else if (position == 57) { x = 6; y = 2; }
        else if (position == 58) { x = 6; y = 3; }
        else if (position == 59) { x = 6; y = 4; }
        else if (position == 60) { x = 6; y = 5; }
        else if (position == 61) { x = 6; y = 6; }
        else if (position == 62) { x = 6; y = 7; }
        else if (position == 63) { x = 6; y = 8; }

        else if (position == 64) { x = 7; y = 0; }
        else if (position == 65) { x = 7; y = 1; }
        else if (position == 66) { x = 7; y = 2; }
        else if (position == 67) { x = 7; y = 3; }
        else if (position == 68) { x = 7; y = 4; }
        else if (position == 69) { x = 7; y = 5; }
        else if (position == 70) { x = 7; y = 6; }
        else if (position == 71) { x = 7; y = 7; }
        else if (position == 72) { x = 7; y = 8; }

        else if (position == 73) { x = 8; y = 0; }
        else if (position == 74) { x = 8; y = 1; }
        else if (position == 75) { x = 8; y = 2; }
        else if (position == 76) { x = 8; y = 3; }
        else if (position == 77) { x = 8; y = 4; }
        else if (position == 78) { x = 8; y = 5; }
        else if (position == 79) { x = 8; y = 6; }
        else if (position == 80) { x = 8; y = 7; }
        else if (position == 81) { x = 8; y = 8; }

        else {
            cout << "Invalid position. Please enter a number between 1 and 81.\n";
        }
    }

};

template <typename T>
class giantXOrandomPlayer : public RandomPlayer <T> {
public:
    giantXOrandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
        this->name = "Computer";
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    
    void getmove(int& x, int& y) {
        int position = rand() % 81 + 1;
        if (position == 1) { x = 0; y = 0; }
        else if (position == 2) { x = 0; y = 1; }
        else if (position == 3) { x = 0; y = 2; }
        else if (position == 4) { x = 0; y = 3; }
        else if (position == 5) { x = 0; y = 4; }
        else if (position == 6) { x = 0; y = 5; }
        else if (position == 7) { x = 0; y = 6; }
        else if (position == 8) { x = 0; y = 7; }
        else if (position == 9) { x = 0; y = 8; }

        else if (position == 10) { x = 1; y = 0; }
        else if (position == 11) { x = 1; y = 1; }
        else if (position == 12) { x = 1; y = 2; }
        else if (position == 13) { x = 1; y = 3; }
        else if (position == 14) { x = 1; y = 4; }
        else if (position == 15) { x = 1; y = 5; }
        else if (position == 16) { x = 1; y = 6; }
        else if (position == 17) { x = 1; y = 7; }
        else if (position == 18) { x = 1; y = 8; }

        else if (position == 19) { x = 2; y = 0; }
        else if (position == 20) { x = 2; y = 1; }
        else if (position == 21) { x = 2; y = 2; }
        else if (position == 22) { x = 2; y = 3; }
        else if (position == 23) { x = 2; y = 4; }
        else if (position == 24) { x = 2; y = 5; }
        else if (position == 25) { x = 2; y = 6; }
        else if (position == 26) { x = 2; y = 7; }
        else if (position == 27) { x = 2; y = 8; }

        else if (position == 28) { x = 3; y = 0; }
        else if (position == 29) { x = 3; y = 1; }
        else if (position == 30) { x = 3; y = 2; }
        else if (position == 31) { x = 3; y = 3; }
        else if (position == 32) { x = 3; y = 4; }
        else if (position == 33) { x = 3; y = 5; }
        else if (position == 34) { x = 3; y = 6; }
        else if (position == 35) { x = 3; y = 7; }
        else if (position == 36) { x = 3; y = 8; }

        else if (position == 37) { x = 4; y = 0; }
        else if (position == 38) { x = 4; y = 1; }
        else if (position == 39) { x = 4; y = 2; }
        else if (position == 40) { x = 4; y = 3; }
        else if (position == 41) { x = 4; y = 4; }
        else if (position == 42) { x = 4; y = 5; }
        else if (position == 43) { x = 4; y = 6; }
        else if (position == 44) { x = 4; y = 7; }
        else if (position == 45) { x = 4; y = 8; }

        else if (position == 46) { x = 5; y = 0; }
        else if (position == 47) { x = 5; y = 1; }
        else if (position == 48) { x = 5; y = 2; }
        else if (position == 49) { x = 5; y = 3; }
        else if (position == 50) { x = 5; y = 4; }
        else if (position == 51) { x = 5; y = 5; }
        else if (position == 52) { x = 5; y = 6; }
        else if (position == 53) { x = 5; y = 7; }
        else if (position == 54) { x = 5; y = 8; }

        else if (position == 55) { x = 6; y = 0; }
        else if (position == 56) { x = 6; y = 1; }
        else if (position == 57) { x = 6; y = 2; }
        else if (position == 58) { x = 6; y = 3; }
        else if (position == 59) { x = 6; y = 4; }
        else if (position == 60) { x = 6; y = 5; }
        else if (position == 61) { x = 6; y = 6; }
        else if (position == 62) { x = 6; y = 7; }
        else if (position == 63) { x = 6; y = 8; }

        else if (position == 64) { x = 7; y = 0; }
        else if (position == 65) { x = 7; y = 1; }
        else if (position == 66) { x = 7; y = 2; }
        else if (position == 67) { x = 7; y = 3; }
        else if (position == 68) { x = 7; y = 4; }
        else if (position == 69) { x = 7; y = 5; }
        else if (position == 70) { x = 7; y = 6; }
        else if (position == 71) { x = 7; y = 7; }
        else if (position == 72) { x = 7; y = 8; }

        else if (position == 73) { x = 8; y = 0; }
        else if (position == 74) { x = 8; y = 1; }
        else if (position == 75) { x = 8; y = 2; }
        else if (position == 76) { x = 8; y = 3; }
        else if (position == 77) { x = 8; y = 4; }
        else if (position == 78) { x = 8; y = 5; }
        else if (position == 79) { x = 8; y = 6; }
        else if (position == 80) { x = 8; y = 7; }
        else if (position == 81) { x = 8; y = 8; }
    }
};