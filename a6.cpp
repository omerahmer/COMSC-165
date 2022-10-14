#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

int search(char source[], char target[]);
void append(char[]);


int main() {
    int count = 0;
    const int SIZE = 51;
    char input[SIZE];
    cout << "Enter string of length no more than " << (SIZE-1) << " characters:" << endl;
    cin.getline(input, SIZE);
    cout << "Current string: ";
    while (input[count] != '\0') {
        cout << input[count];
        cout << endl;
        count++;
    }
    cout << "Choose an option: " << endl << "( s - search, i - insert, a - append, d - delete, r - replace, e - exit)";
    char option;
    cin >> option;
    switch (option) {
        case 's':
            cout << "Enter a string to be searched: " << endl;
            char searchQuery[SIZE];
            cin.getline(searchQuery, SIZE);
            cout << "Searching for: ";
            int count2 = 0;
            while (searchQuery[count2] != '\0') {
                cout << searchQuery[count2];
                cout << endl;
                count2++;
            }
            int index = search(input, searchQuery);
            if (index != -1) {
                cout << "Found at position " << index << endl;
            }
            else {
                cout << "String not found" << endl;
            }
            break;
        case 'i':
            
    }
} 

int search(char source[], char target[]) {
    cout << "Enter a string to be searched: " << endl;

    int sourceLen = strlen(source);
    int targetLen = strlen(target);
    int index = -1;

    for (int i = 0; i < (sourceLen-(targetLen-1)); i++) {
        if (strncmp(&source[i], target, targetLen) == 0) {
            index = i;
        }
        break;
    }

    return index;
}