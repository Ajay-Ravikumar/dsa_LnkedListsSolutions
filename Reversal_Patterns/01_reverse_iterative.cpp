/* 11. Reverse a singly linked list (iterative) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* reverseIter(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original: "; printList(head);
    head = reverseIter(head);
    cout << "Reversed: "; printList(head);
}
