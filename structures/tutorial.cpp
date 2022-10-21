#include <iostream>
using namespace std;

// blueprint for type Student
struct Student {
    string name;
    int id;
    double gpa;
};

void print(int i) {
    cout << i << endl;
}

int main() {
    Student s[2];
    s[0].name = "Omer";
    s[0].id = 2014063;
    s[0].gpa = 3.5;

    for (Student& i : s) {
        cout << i.name << endl;
        cout << i.id << endl;
        cout << i.gpa << endl;
    }
}