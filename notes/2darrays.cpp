#include <iostream>
using namespace std;

void printIt(int);

int main()  {
    const int ROWS = 4, COLS = 3;
    int numbers[ROWS][COLS]; // creates a ROWS x COLS 2D array
    
    numbers[2][2] = 66;
    numbers[0][1] = 99;

    cout << numbers[2][2] << ", " << numbers[0][1] << endl;

    printIt(numbers[2][2]);

    const int WEEKS = 2, DAYS = 7;
    int steps[WEEKS][DAYS];

    for (int i = 0; i < WEEKS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Enter your steps for that day: " << endl;
            cin >> steps[i][j];
        }
    }
    int totalSteps = 0;
    for (int i = 0; i < WEEKS; i++) {
        for (int j = 0; j < DAYS; j++) {
            totalSteps += steps[i][j];
        }
    }
    cout << "Your total steps for two weeks was: " << totalSteps << endl;
}

void printIt(int a) {
    cout << a << endl;
}