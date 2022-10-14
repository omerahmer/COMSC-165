/*
 Description: This program returns statistics about the number of movies students have watched
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 9/28/22
 Status: Complete
 */

#include <iostream>
using namespace std;

double computeMean(int*, int);
double computeMedian(int*, int);
int computeMode(int*, int);

int main() {
    cout << "Enter number of students surveyed: ";
    int numStudents;
    cin >> numStudents;

    int* numMovies = new int[numStudents];

    cout << "Enter number of movies watched for each student: " << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i+1 << ": " << endl;
        cin >> *(numMovies + i);
    }

    double mean = computeMean(numMovies, numStudents);
    cout << "The mean number of movies watched by the " << numStudents << " students is: " << mean << endl;

    double median = computeMedian(numMovies, numStudents);
    cout << "The median number of movies watched by the " << numStudents << " students is: " << median << endl;

    int mode = computeMode(numMovies, numStudents);
    cout << "The mode number of movies watched by the " << numStudents << " students is: " << mode << endl;

}

double computeMean(int* num, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(num+i);
    }
    double average = (double) sum/size;
    return average;
}

double computeMedian(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (*(nums+i) > *(nums+j)) {
                int temp = *(nums+i);
                *(nums+i) = *(nums+j);
                *(nums+j) = temp;
            }
        }
    }
    if (size % 2 != 0) {
        return (double) (*(nums+(size/2))/2);
    }
    else {
        return (double) (*(nums + ((size-1))) + *(nums + (size/2)));
    }
}

int computeMode(int* nums, int size) {
    int number = *(nums);
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<size; i++)
    {
        if (*(nums+i) == number) {
            ++count;
        }
        else {
                if (count > countMode) 
                {
                    countMode = count;
                    mode = number;
                }
            count = 1;
            number = *(nums+i);
    }
    }
    return mode;
}