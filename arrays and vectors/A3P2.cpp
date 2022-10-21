/*
 Description: This program runs a simulation of a 2-player tic-tac-toe game
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 9/10/22
 Status: Complete
 */

#include <iostream>
using namespace std;

// Determines whose turn it is
void player_turn();

// Displays board
void display();

// Initialize empty board with asterisks
char board[3][3] = {{'*','*','*'}, {'*','*','*'}, {'*','*','*'}};

bool draw = false;

int main() {
    bool gameover;

    // Checks for empty boxes
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' || board[i][j] != 'O') {
                gameover = false;
            }
        }
    }

    // Checks rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] == board[i][2]) || (board[0][i] == board[1][i] == board[2][i])) {
            gameover = true;
        } 
    }

    if (board[0][0] == board [1][1] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        gameover = true;
    }

    while (gameover) {
        display();
        player_turn();
        gameover = false;
    }

    if (draw == true) {
        cout << "Draw!" << endl;
    }
}

void player_turn() {
    char turn = 'X';
    int input_row, input_column;
    if (turn == 'X') {
        cout << "Player 1:" << endl;
        cout << "Enter row and column to place an X:" << endl;
        cout << "Row: ";
        cin >> input_row;
        cout << "Column: ";
        cin >> input_column;
        if ((turn == 'X') && (board[input_row-1][input_column-1] != 'X') && (board[input_row-1][input_column-1] != 'O')) {
            board[input_row][input_column] = 'X';
            turn = 'O';
            display();
        }
    } else if (turn == 'O') {
        cout << "Player 2:" << endl;
        cout << "Enter row and column to place an O:" << endl;
        cout << "Row: ";
        cin >> input_row;
        cout << "Column: ";
        cin >> input_column;
        if ((turn == 'X') && (board[input_row-1][input_column-1] != 'X') && (board[input_row-1][input_column-1] != 'O')) {
            board[input_row][input_column] = 'O';
            turn = 'X';
            display();
        }
    }
}

void display() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "  ";
        }
        cout << endl << endl;
    }
}