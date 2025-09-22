/* 6. Delete a node at a given position */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void deleteAtPos(Node*& head, int pos) {
    if (!head) return;
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp || !temp->next) return;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
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
    head->next->next = new Node(3);

    cout << "Before: "; printList(head);
    deleteAtPos(head, 2);
    cout << "After: "; printList(head);
    return 0;
}
