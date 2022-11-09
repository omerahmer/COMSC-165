/*
 Description: This program creates a linked list and the user can add a number, delete it, search the list, and display it
 Author: Omer Ahmer
 COMSC 165-5065
 Date: 11/8/22
 Status: Complete
 */

#include <iostream>
#include <string>
using namespace std;

struct entry {
    int number;
    entry *next;
};

char menu();
void orderedInsert(entry* &head, int choice);
void deleteEntry(entry* &head, int choice);
entry* search(entry *head, int choice);
void display(entry* head);

int main() {
    entry *head = NULL;
    entry *ptr;
    char c;
    do {
        int i;
        char choice = menu();
        switch (choice) {
            case 'A':
                cout << "Enter number you would like to add (-9999 to exit):" << endl;
                cin >> i;
                orderedInsert(head, i);
                break;
            case 'B':
                cout << "Enter number you would like to delete:" << endl;
                cin >> i;
                deleteEntry(head, i);
                break;
            case 'C':
                cout << "Enter number you would like to search for:" << endl;
                cin >> i;
                ptr = search(head, i);
                break;
            case 'D':
                display(head);
                break;
        }
        cout << "Enter z to continue" << endl;
        cin >> c;
    } while (c == 'z');   
}

char menu() {
    char input;
    cout << "A. Add a number" << endl << "B. Delete a number" << endl << "C. Search for a number" << endl << "D. Display the whole list of numbers" << endl << "E. Exit" << endl;
    cout << "Enter your choice:" << endl;
    cin >> input;
    return input;
}

void orderedInsert(entry* &head, int choice) {
    entry *current;
    entry *node = new entry;
    node->number = choice;
    node->next = NULL;
    if ((head == NULL) || (head->number >= node->number)) {
        node->next = head;
        head = node;
    }
    else {
        current = head;
        while (current->next != NULL && current->next->number < choice) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

void deleteEntry(entry* &head, int choice) {
    entry *current;
    entry *previous;
    current = head;
    previous = NULL;
    while (current != NULL && current->number != choice) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        cout << "The number you want to delete isn't on the list." << endl;
    }
    else if (previous == NULL) {
        head = head->next;
        delete current;
    }
    else {
        previous->next = current->next;
        delete current;
    }
}

entry *search(entry *head, int choice) {
    entry *current = head;
    while (current) {
        if (current->number == choice) {
            return current;
        }
        current = current->next;
    }
    if (current == NULL) {
        cout << "Number not found" << endl;
    }
    else {
        cout << "The number " << current << " was found" << endl;
    }
}

void display(entry* head) {
    entry* current = head;
    while (current != NULL) {
        cout << current->number << " " << endl;
        current = current->next;
    }
    cout << endl;
}