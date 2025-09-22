/* 9. Print a linked list in reverse (without modifying it) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void printReverse(Node* head) {
    if (!head) return;
    printReverse(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Reverse print: ";
    printReverse(head);
    cout << endl;
    return 0;
}
