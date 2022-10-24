#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void perror();
void extra();

int main() {
    // display the contents of a text file
    ifstream inputFile;
    inputFile.open("main");
    if (inputFile) {
        
        string input;
        
        // attempt to read first line of file
        getline(inputFile, input);
        
        while (inputFile) { // while we have successfully read a line of text
            cout << input << endl; // display that line
            getline(inputFile, input); // attempt to get the next line
        }
        inputFile.close();
    }
    else {
        perror();
    }
}

void perror() {
    cout << "Error opening files!" << endl;
}

void extra() {
    // read/write a single integer to/from text file
    int x,y;
    ofstream fout;

    cout << "Give me an int to write to the file: ";
    cin >> x;

    fout.open("output.txt"); // attempt to open output.txt for writing
    if (fout) { // if the file was opened successfully, then do some stuff
        fout << x;
        fout.close();
    }
    else {
        perror();
    }

    // read the int from the text file and store it in y
    ifstream fin;
    y=0;

    fin.open("output.txt"); // atempt to open output.txt for reading
    if (fin) {
        fin >> y;
        fin.close();
    }
    else {
        perror();
    }
    cout << "y: " << y << endl;
    const int LENGTH = 7;
    ofstream output;
    double d[LENGTH] = {1.1,2.2,3.3,4.4,5.5,6.6,13.13}, e[LENGTH];
    output.open("array.txt");
    if (output) {
        for (int i = 0; i < LENGTH; i++) {
            output << setw(10) << fixed << setprecision(3) << d[i] << " ";
        }
        output.close();
    }
    else {
        perror();
    }
    
    ifstream input;
    
    input.open("array.txt");
    if (input) {
        for (int i = 0; i < LENGTH; i++) {
            input >> e[i];
        }
        input.close();
        
        for (int j = 0; j < LENGTH; j++) {
            cout << e[j] << " ";
        }
    }
    else {
        perror();
    }
}
