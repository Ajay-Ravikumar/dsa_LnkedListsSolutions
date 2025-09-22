/* 3. Insert a node at a given position (1-based index) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertAtPos(Node*& head, int data, int pos) {
    if (pos == 1) {
        Node* node = new Node(data);
        node->next = head;
        head = node;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return;
    Node* node = new Node(data);
    node->next = temp->next;
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
    insertAtPos(head, 1, 1);
    insertAtPos(head, 2, 2);
    insertAtPos(head, 3, 3);
    insertAtPos(head, 99, 2);
    printList(head);
    return 0;
}
