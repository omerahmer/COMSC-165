#include <iostream>
#include <fstream>
using namespace std;

struct SoccerPlayer {
    char first[31];
    char last[31];
    int month, day, year;
};

void inputData(string filename, SoccerPlayer players[]);
void display(SoccerPlayer players[]);
void sort(SoccerPlayer players[]);
void swapping(SoccerPlayer&, SoccerPlayer&);
int playerSearch(SoccerPlayer players[], char[]);
void find(SoccerPlayer players[]);
const int PLAYERS_SIZE = 10;

int main() {
    int option;
    string filename;
    SoccerPlayer players[PLAYERS_SIZE];
    SoccerPlayer copyPlayers[PLAYERS_SIZE];

    do {
        cout << "1 — input data, 2 — display original data, 3 — sort data, 4 — display sorted data, 5 — search by last name, 6 — exit" << endl;
        switch (option) {
            case 1:
                cout << "Enter filename: " << endl;
                cin >> filename;
                inputData(filename, players);
                break;
            case 2:
                display(players);
                break;
            case 3:
                cout << "Sorting data..." << endl;
                sort(players);
                cout << "Data sorted." << endl;
                break;
            case 4:
                display(copyPlayers);
            case 5:
                char input[21];
                cout << "Enter first few characters of player you want to find: " << endl;
                cin >> input;
                int index = playerSearch(players, input);
        }
    } while (option != 6);
}

void inputData(string filename, SoccerPlayer players[]) {
    ifstream ifs;
    ifs.open(filename.data());
    if (ifs) {
        for (int i = 0; i < PLAYERS_SIZE; i++) {
            ifs >> players[i].last;
            ifs >> players[i].first;
            ifs >> players[i].month;
            ifs >> players[i].day;
            ifs >> players[i].year;
            i++;
        }
    }
}

void display(SoccerPlayer players[]) {
    for (int i = 0; i < PLAYERS_SIZE; i++) {
        cout << players[i].last << " ";
        cout << players[i].first << " ";
        cout << players[i].day << " ";
        cout << players[i].month << " ";
        cout << players[i].year << endl;
    }
}

void sort(SoccerPlayer players[]) {
    int *index;
    index = new int[PLAYERS_SIZE];
    int i, j, min;
    for (int a = 0; a < PLAYERS_SIZE; a++) {
        index[a] = i;
    }
    for (i = 0; i < PLAYERS_SIZE - 1; i++) {
        for (j = i+1; j < PLAYERS_SIZE; j++) {
            if (strcmp(players[index[min]].last, players[index[j]].last) > 0) {
                min = j;
            }
        } 
        if (min != i) {
            int temp = index[min];
            index[min] = index[i];
            index[i] = temp;
        } 
    }
    display(players);
}