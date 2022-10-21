//
//  Description: This program counts the votes of the users' favorite beverages
//  Author: Omer Ahmer
//  Date: 8/23/22
//  COMSC-165-5065
//  Status: Complete

#include <iostream>
using namespace std;

int main()
{
    int coffee = 0, tea = 0, coke = 0, orange = 0, votes = 0;
    int count = 1;
    
    cout << "1. Coffee  2. Tea  3. Coke  4. Orange Juice" << endl;
    
    while (votes != -1) {
        cout << "Please input the favorite beverage of person #" << count << ":" << endl;
        cout << "Choose option 1, 2, 3, or 4 from the above menu or type -1 to exit." << endl;
        cin >> votes;
        switch (votes) {
            case 1:
                coffee++;
                break;
            case 2:
                tea++;
                break;
            case 3:
                coke++;
                break;
            case 4:
                orange++;
                break;
        }
        count++;
    }
    cout << "The total number of people surveyed is " << count << ". The results are as follows: " << endl;
    cout << "Votes for Beverages" << endl;
    cout << "********************************" << endl;
    cout << "Coffee: " << coffee << endl;
    cout << "Tea: " << tea << endl;
    cout << "Coke: " << coke << endl;
    cout << "Orange Juice: " << orange << endl;
}
