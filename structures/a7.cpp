/*
 Description: This program creates a struct of soccer players, and can display, sort, swap, and search different values for each soccer player.
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 10/21/22
 Status: Complete
 */

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
int playerSearch(SoccerPlayer players[]);
const int PLAYERS_SIZE = 10;

int main() {
    int option;
    string filename;
    SoccerPlayer players[PLAYERS_SIZE];
    SoccerPlayer copyPlayers[PLAYERS_SIZE];

    do {
        cout << "1 — input data, 2 — display original data, 3 — sort data, 4 — display sorted data, 5 — search by last name, 6 — exit" << endl;
        cin >> option;
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
                int index = playerSearch(players);
        }
    } while (option == 6);
}

void inputData(string filename, SoccerPlayer players[]) {
    ifstream ifs;
    ifs.open("names.txt");
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
        cout << players[i].first << " ";
        cout << players[i].last << " ";
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

void swapping(SoccerPlayer &player1, SoccerPlayer &player2) {
    char temp_array[20];

    strcpy(temp_array, player1.first);
    strcpy(player1.first, player2.first);
    strcpy(player2.first, temp_array);

    strcpy(temp_array, player1.last);
    strcpy(player1.last, player2.last);
    strcpy(player2.last, temp_array);

    int tempday = player1.day;
    player1.day = player2.day;
    player2.day = tempday;

    int tempmonth = player1.month;
    player1.month = player2.month;
    player2.month = tempmonth;

    int tempyear = player1.year;
    player1.year = player2.year;
    player2.year = tempyear;

}

int playerSearch(SoccerPlayer players[]) {
    string last = "";
    while (last != "exit") {
        int found = 1;
        int flag = 0;
        char input[21];
        cout << "Enter first few characters of player you want to find: " << endl;
        cin >> input;

        for (int i = 0; i < PLAYERS_SIZE; i++) {
            for (int j = 0; j < last.length(); j++) {
                if (players[i].last[j] != last.at(j)) {
                    found = 0;
                    break;
                }
            }
            if (found == 1) {
                flag = 1;
                display(players);
            }
        }
        if (flag == 0) {
            cout << "Not found." << endl;
        }
    }
}