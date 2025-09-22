/* 2. Insert a node at the tail of a singly linked list */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertTail(Node*& head, int data) {
    Node* node = new Node(data);
    if (!head) {
        head = node;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
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
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    printList(head);
    return 0;
}
