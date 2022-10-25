#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    int a[] = {1, 2, 3};
    int b[3];

    // write array a to a file dog.bin
    fstream f;

    // attempt to open/create dog.bin
    f.open("dog.bin", ios::out|ios::binary);

    // verify file did actually open
    if (f) {
        // write to the file
        f.write(reinterpret_cast<char*>(a), 3*sizeof(int));

        // close the file
        f.close();
    }
    else {
        cout << "Error opening file for writing!" << endl;
        exit(1);
    }

    // write the contents of dog.bin to array b

    // attempt to open dog.bin for reading
    f.open("dog.bin", ios::in|ios::binary);

    // verify file opened
    if (f) {
        // read the file
        f.read(reinterpret_cast<char*>(b), 3*sizeof(int));
        f.close();
    }
    else {
        cout << "Error opening file for reading!" << endl;
        exit(1);
    }

    for (int i = 0; i < 3; i++) {
        cout << b[i] << " " << endl;
    }

    cin.get();
    
}