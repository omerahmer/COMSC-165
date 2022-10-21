/*
 Description: This program converts the existing arrays to vectors
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 9/10/22
 Status: Complete
 */


#include <iostream>
#include <vector>

using namespace std;

bool testPIN(const vector<int>, const vector<int>);

int main()
{
    vector<int> pin_1 {2, 4, 1, 8, 7, 9, 0}; // Base set of values.
    vector<int> pin_2 {2, 4, 6, 8, 7, 9, 0}; // Only 1 element is different from pin1.
    vector<int> pin_3 {1, 2, 3, 4, 5, 6, 7}; // All elements are different from pin1.


    if (testPIN(pin_1, pin_2))
        cout << "Error: pin_1 and pin_2 report to be the same.\n";
    else
        cout << "Success: pin_1 and pin 2 are different.\n";


    if (testPIN(pin_1, pin_3))
        cout << "ERROR: pin_1 and pin_3 report to be the same.\n";
    else
        cout << "SUCCESS: pin_1 and pin_3 are different.\n";
    

    if (testPIN(pin_1, pin_2))
        cout << "SUCCESS: pin_1 and pin_1 report to be the same.\n";
    else
        cout << "ERROR: pin_1 and pin_1 report to be different.\n";
    
    
    return 0;
}

//******************************************************************
// The following function accepts two int arrays. The arrays are *
// compared. If they contain the same values, true is returned. *
// If the contain different values, false is returned.
//******************************************************************

bool testPIN(const vector<int> customerPIN, const vector<int> databasePIN)
{
    for(int index = 0; index < customerPIN.size(); index++)
    {
        if (customerPIN[index] != databasePIN[index])
            return false; // We've found two different values.
    }
    return true; // If we make it this far, the values are the same.
}
