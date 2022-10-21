#include <iostream>
#include <cctype>
using namespace std;

int main() {
    const int SIZE = 25;
    char location[SIZE] = "Dublin, ";
    cout << strlen(location) << endl;
    char state[3] = "CA";
    cout << strcat(location, state) << endl;

}