/* 11. Reverse a singly linked list (iterative) */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = d; node->next = NULL; return node;
}

struct Node* reverseIter(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(1); head->next = newNode(2); head->next->next = newNode(3);
    printf("Original: "); printList(head);
    head = reverseIter(head);
    printf("Reversed: "); printList(head);
}
