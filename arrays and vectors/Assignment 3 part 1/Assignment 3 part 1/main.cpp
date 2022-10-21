/*
 Description: This program gets temperatures from user, sorts the array filled with the temperatures, and returns the average
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 9/10/22
 Status: Complete
 */


#include <iostream>
#include <iomanip>
using namespace std;

void sorting(int size, int array[size]);
void displayAvg(int size, int array[size]);

int main() {
    int count;
    const int MAX = 10;
    cout << "Enter number of temperatures: " << endl;
    cin >> count;
    
    if (count > MAX) {
        cout << "You have entered too many temperatures. Please try again:" << endl;
        cin >> count;
    }
    
    int temp[count];
    
    for (int i = 0; i < count; i++) {
        cout << "Enter temperature " << i+1 << ":" << endl;
        cin >> temp[i];
    }
    
    sorting(count, temp);
    displayAvg(count, temp);
    
}

void sorting(int size, int array[size]) {
    int temp, i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    cout << "The temperatures you have entered in ascending order are: ";
    for (int k = 0; k < size; k++) {
        cout << array[k] << endl;
    }
}

void displayAvg(int size, int array[size]) {
    double sum = 0, avg;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    avg = sum/size;
    cout << "The average of the temperatures you entered is: " << setprecision(4) << avg << endl;
}
