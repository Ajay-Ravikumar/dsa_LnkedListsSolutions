/* 7. Find the length of a linked list (iterative + recursive) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

int lengthIter(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int lengthRec(Node* head) {
    return head ? 1 + lengthRec(head->next) : 0;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);

    cout << "Length (iter): " << lengthIter(head) << endl;
    cout << "Length (rec): " << lengthRec(head) << endl;
    return 0;
}
