/*
 Description: This program swaps two numbers that were input by the user, and returns them
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 8/29/22
 Status: Complete
 */

#include <iostream>
using namespace std;

void swapping(float &number1, float &number2);

int main() {
    float n1, n2;
    cout << "Enter first number: " << endl;
    cin >> n1;
    cout << "Enter second number: " << endl;
    cin >> n2;
    cout << "You entered the numbers " << n1 << " and " << n2 << endl;
    swapping(n1, n2);
    cout << "After swapping, the first number is " << n1 << " which was the value of the second number." << endl;
    cout << "After swapping, the second number is " << n2 << " which was the value of the first number." << endl;
    
    return 0;
}

void swapping(float &number1, float &number2) {
    float temp;
    temp = number1;
    number1 = number2;
    number2 = temp;
}
