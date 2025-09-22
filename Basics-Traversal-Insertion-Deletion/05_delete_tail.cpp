/* 5. Delete a node at the tail of a linked list */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);

    cout << "Before: "; printList(head);
    deleteTail(head);
    cout << "After: "; printList(head);
    return 0;
}
