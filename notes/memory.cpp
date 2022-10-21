#include <iostream>
using namespace std;

int main() {
    // statically allocated memory is allocated at compile time
    int i;
    int a[10];
    // 44 bytes: 4 from int, 40 from 10 integer array

    // dynamically allocated memory is allocated at "run time"
    int* iptr = new int;        // dynamically allocating an int
    int* aptr = new int[10];    // dynamically allocating an int array

    i = 5;
    a[3] = 87;

    aptr[3] = 87;
    *iptr = 5;

    cout << "How many numbers do you want to enter: " << endl;
    int size;                   // statically allocated since we know the input will be an integer
    cin >> size;

    int* numbersList = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter a value: " << endl;
        cin >> *(numbersList + i);
    }

    int total = 0;

    for (int j = 0; j < size; j++) {
        total += numbersList[j];
    }

    cout << "Total of values entered was: " << total << endl;

    delete iptr;
    delete [] aptr;
    delete [] numbersList;

    return 0;
}