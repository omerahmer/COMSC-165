/*
 Description: This program reads data from a file, encrypts it, writes the encrypted data to another file, and can return the decrypted data
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 10/25/22
 Status: Complete
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// function to get data from file and encrypt
void encrypt(string filename);

// function to decrypt from other file
void decrypt(string source);

int main() {
    string source;
    cout << "Enter source filename: ";
    getline(cin, source);
    encrypt(source);
}

void encrypt(string filename) {
    string toEncrypt;
    ifstream input;
    input.open(filename);
    if (input) {        
        // attempt to read first line of file
        getline(input, toEncrypt);
        
        while (input) { // while we have successfully read a line of text
            cout << "The original string is: " << toEncrypt << endl; // display that line
            getline(input, toEncrypt); // attempt to get the next line
        }
        input.close();
    }
    else {
        cout << "Could not open file" << endl;
    }

    for (int i = 0; i < toEncrypt.size(); i++) {
        toEncrypt[i] += 10;
    }

    ofstream out("encrypted.txt");
    out << toEncrypt;
    out.close();

    decrypt("encrypted.txt");
}

void decrypt(string source) {
    ifstream input;
    string toDecrypt;
    input.open(source);
    if (input) {
        getline(input, toDecrypt);
        while (input) {
            cout << "The encrypted string is: " << toDecrypt << endl;
            getline(input, toDecrypt);
        }
        input.close();
    }
    else {
        cout << "Could not open file" << endl;
    }
    for (int i = 0; i < toDecrypt.size(); i++) {
        toDecrypt[i] -= 10;
    }

    cout << "The decrypted string is: " << toDecrypt << endl;

}