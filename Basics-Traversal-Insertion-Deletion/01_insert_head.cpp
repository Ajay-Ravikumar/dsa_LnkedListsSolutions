/* 1. Insert a node at the head of a singly linked list */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertHead(Node*& head, int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    printList(head);
    return 0;
}
