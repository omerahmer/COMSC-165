/*
 Description: Determines letter grade after user inputs a certain amount of grades by taking the average of all of the grades, and then comparing the average against a grading scale
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 8/29/22
 Status: Complete
 */

#include <iostream>
using namespace std;

int calcAvg(int ct, double &average);

int main() {
    // initializes variables
    int count;
    double avg;
    char letter;
    // asks user for input
    cout << "Enter number of grades:" << endl;
    cin >> count;
    // uses calcAvg function to find average grade
    int grade = calcAvg(count, avg);
    
    // set of conditional statements to compare number grade to a letter
    if (grade >= 90) {
        letter = 'A';
    }
    else if (grade >= 80) {
        letter = 'B';
    }
    else if (grade >= 70) {
        letter = 'C';
    }
    else if (grade >= 60) {
        letter = 'D';
    }
    else {
        letter = 'F';
    }
    
    // outputs final grade
    cout << "Your average grade is a " << letter << endl;
    
    return 0;
}

// calculates and returns the average grade by dividing the total percentage points by the count of grades inputted
int calcAvg(int ct, double &average) {
    int total = 0;
    int percent;
    for (int i = 0; i < ct; i++) {
        cout << "Enter grade between 0-100:" << endl;
        cin >> percent;
        total += percent;
    }
    average = total/ct;
    return average;
}
