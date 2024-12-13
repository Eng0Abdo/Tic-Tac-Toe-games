#include "BoardGame_Classes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>

class wordBoard : public Board<T> {
private:
	string content;
	vector<string> words;
public:
	wordBoard() {
		this->rows = 3;
		this->columns = 3;
		this->board = new char* [this->rows];
		int position = 1; // Start numbering from 1
		for (int i = 0; i < this->rows; i++) {
			this->board[i] = new char[this->columns];
			for (int j = 0; j < this->columns; j++) {
				this->board[i][j] = '0' + position; // Convert number to char
				position++;
			}
		}
		this->n_moves = 0;

		// Read file content and populate words vector
		readFile();
		setVector();
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


	// Display the board and the pieces on it
void display_board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "| " << this->board[i][j] << " |";
		}
		cout << endl;
	}
	cout << endl;
}

	// Read the file Content
void readFile() {
	fstream file("dic.txt");
	stringstream f_content;
	f_content << file.rdbuf();
	content = f_content.str();
	file.close();
}

	// get all the words in one vector
	void setVector() {
		stringstream ss(content);
		string word;
		while (ss >> word) {
			words.push_back(word);
		}
	}

	// Hashing search for speed
	bool hashSearch(const string& target) {
		unordered_set<string> hashSet(words.begin(), words.end());
		return hashSet.find(target) != hashSet.end();
	}

	// Returns true if there is any winner
	bool is_win() {
		string winWord = "";

	// Check rows and columns
		for (int i = 0; i < 3; i++) {
			winWord = "";
			winWord += this->board[i][0]; winWord += this->board[i][1]; winWord += this->board[i][2];
			if (hashSearch(winWord)) {
				return true;
			}
			winWord = "";
			winWord += this->board[0][i]; winWord += this->board[1][i]; winWord += this->board[2][i];
			if (hashSearch(winWord)) {
				return true;
			}
		}

		// Check diagonals
		winWord = "";
		winWord += this->board[0][0]; winWord += this->board[1][1]; winWord += this->board[2][2];
		if (hashSearch(winWord)) return true;
		winWord = "";
		winWord += this->board[0][2]; winWord += this->board[1][1]; winWord += this->board[2][0];
		if (hashSearch(winWord)) return true;

		return false;
	}

	// Return true if all moves are done and no winner
	bool is_draw() {
		return (this->n_moves == 9 && !is_win());
	}

	// Return true if the game is over
	bool game_is_over() {
		return is_win() || is_draw();
	}




};

template <typename T>
class wordPlayer : public Player <T> {
private:
	char getChar() {
		string play;
		cin >> play;
		if (play.length() > 1 || !isalpha(play[0])) {
			cout << "Invalid input. Please enter a single alphabetic character.\n";
			getChar();
		}
		cout << endl;
		return toupper(play[0]);
	}

public:

	wordPlayer(string name) : Player<T>(name, ' ') {}



	void getmove(int& x, int& y) {
		
			cout << this->name << ", choose the character you want to play: ";
			this->symbol = getChar();
		
		int position;
		cout << this->name << " (" << this->symbol << "), enter where you want to play (1 to 9): ";
		cin >> position;

		// Map position to board coordinates
		if (position == 1) {
			x = 0; y = 0;
		}
		else if (position == 2) {
			x = 0; y = 1;
		}
		else if (position == 3) {
			x = 0; y = 2;
		}
		else if (position == 4) {
			x = 1; y = 0;
		}
		else if (position == 5) {
			x = 1; y = 1;
		}
		else if (position == 6) {
			x = 1; y = 2;
		}
		else if (position == 7) {
			x = 2; y = 0;
		}
		else if (position == 8) {
			x = 2; y = 1;
		}
		else if (position == 9) {
			x = 2; y = 2;
		}
		else {
			cout << "Invalid input Please enter a number between 1 and 9.\n";
		}
		
	}
};

template <typename T>
class wordRandomPlayer : public RandomPlayer<T> {
private:
	char getRandomChar() {
		std::srand(std::time(0));
		return 'A' + (std::rand() % 26);
	}

public:
	wordRandomPlayer() : RandomPlayer<T>(' ') {
		this->name = "Random Computer Player";
		srand(static_cast<unsigned int>(time(nullptr)));
	}

	void getmove(int& x, int& y) {
		this->symbol = getRandomChar();
		int position = (rand() % 9) + 1;
		if (position == 1) {
			x = 0; y = 0;
		}
		else if (position == 2) {
			x = 0; y = 1;
		}
		else if (position == 3) {
			x = 0; y = 2;
		}
		else if (position == 4) {
			x = 1; y = 0;
		}
		else if (position == 5) {
			x = 1; y = 1;
		}
		else if (position == 6) {
			x = 1; y = 2;
		}
		else if (position == 7) {
			x = 2; y = 0;
		}
		else if (position == 8) {
			x = 2; y = 1;
		}
		else if (position == 9) {
			x = 2; y = 2;
		}
	}
};



//void wordTicTac() {
//    int choice;
//    Player<char>* players[2];
//    wordBoard<char>* theBoard = new wordBoard<char>();
//    string player1Name, player2Name;
//
//    cout << "Welcome to Word tic tac toe Game. :)\n";
//
//    cout << "Enter Player 1 name: ";
//    cin >> player1Name;
//    cout << "Choose Player 1 type:\n";
//    cout << "1. Human\n";
//    cout << "2. Random Computer\n";
//    cin >> choice;
//
//
//    switch (choice) {
//    case 1:
//        players[0] = new wordPlayer<char>(player1Name);
//        break;
//    case 2:
//        players[0] = new wordRandomPlayer<char>();
//        break;
//    default:
//        cout << "Invalid choice for Player 1. Exiting the game.\n";
//        delete theBoard;
//        wordTicTac();
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
//        players[1] = new wordPlayer<char>(player2Name);
//        break;
//    case 2:
//        players[1] = new wordRandomPlayer<char>();
//        break;
//    default:
//        cout << "Invalid choice for Player 2. Exiting the game.\n";
//        delete players[0];
//        delete theBoard;
//        wordTicTac();
//    }
//
//
//    GameManager<char> wordGame(theBoard, players);
//    wordGame.run();
//
//
//    delete theBoard;
//    for (int i = 0; i < 2; ++i) {
//        delete players[i];
//    }
//}