/*
 Description: Calculates speed to two decimal places based on user input for time and distance traveled.
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 8/29/22
 Status: Complete
 */

#include <iostream>
#include <iomanip>
using namespace std;

void calcSpeed(double hrs, double distance, double &mph);

int main() {
    // declares variables
    double miles, hours, speed;
    
    // gets user input
    cout << "How many miles were traveled?" << endl;
    cin >> miles;
    cout << "How much time did it take in hours?" << endl;
    cin >> hours;
    
    // calculates speed given the user input
    calcSpeed(hours, miles, speed);
    
    // outputs the speed calculated by the calcSpeed function to 2 decimal places
    cout << "Your speed was " << setprecision(4) << speed <<  " miles per hour." << endl;
}

// calculates speed by dividing distance by time
void calcSpeed(double hrs, double distance, double &mph) {
    mph = distance / hrs;
}
