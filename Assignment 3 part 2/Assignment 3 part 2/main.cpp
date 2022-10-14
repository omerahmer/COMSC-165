/*
 Description: This program runs a simulation of a 2-player tic-tac-toe game
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 9/10/22
 Status: Complete
 */

#include <iostream>
using namespace std;


int main() {
    char inputs[3][3] = {{'*','*','*'}, {'*','*','*'}, {'*','*','*'}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 2; j++) {
            cout << inputs[i][j];
        }
    }
}


