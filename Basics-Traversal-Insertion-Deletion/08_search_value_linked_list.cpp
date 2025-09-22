/* 8. Search for a value in a linked list */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

bool search(Node* head, int key) {
    while (head) {
        if (head->data == key) return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);

    cout << "Search 2: " << (search(head, 2) ? "Found" : "Not Found") << endl;
    cout << "Search 5: " << (search(head, 5) ? "Found" : "Not Found") << endl;
    return 0;
}
