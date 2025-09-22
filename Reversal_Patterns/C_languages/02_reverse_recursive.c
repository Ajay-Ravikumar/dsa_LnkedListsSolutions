/* 12. Reverse a singly linked list (recursive) */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = d; node->next = NULL; return node;
}

struct Node* reverseRec(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void printList(struct Node* head) { while(head){printf("%d->",head->data); head=head->next;} printf("NULL\n"); }

int main() {
    struct Node* head = newNode(1); head->next=newNode(2); head->next->next=newNode(3);
    printf("Original: "); printList(head);
    head = reverseRec(head);
    printf("Reversed: "); printList(head);
}
