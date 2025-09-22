/* 12. Reverse a singly linked list (recursive) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* reverseRec(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
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
    head = reverseRec(head);
    cout << "Reversed: "; printList(head);
}
