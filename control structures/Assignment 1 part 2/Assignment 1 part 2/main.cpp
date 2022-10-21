/*
 *  Description: This program counts and returns the total number of sick days for a number of tellers over 3 years
 *  Author: Omer Ahmer
 *  COMSC-165-5065
 *  Date: 8/23/22
 *  Status: Complete
 */

#include <iostream>
using namespace std;

int main()
{
    int tellers = 0;
    int years = 3;
    int sickDays = 0;
    int totalDays = 0;
    cout << "How many tellers have worked at Nation's Bank during each of the last 3 years?" << endl;
    cin >> tellers;
    for (int i = 1; i <= tellers; i++) {
        for (int j = 1; j <= years; j++) {
            sickDays = 0;
            cout << "How many days was teller " << i << " out sick during year " << j << "?" << endl;
            cin >> sickDays;
            totalDays += sickDays;
        }
    }
    cout << "The " << tellers << " tellers were out sick for a total of " << totalDays << " during the last 3 years." << endl;
}
