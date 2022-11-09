#include <iostream>
using namespace std;

// to append, we need to:
// create a node, store data in the node, and append the node to the end of the list

struct Node {
    int value;
    Node* next;
};

int main() {
    Node *head = nullptr;
    int x = 238;
    Node *n = new Node;
    n->value = x;
    n->next = nullptr;
    if (head == nullptr) {
        head = n;
    }
    else {
        Node* p = head;
        while (p != nullptr) {
            p = p->next;
        }
    }
}