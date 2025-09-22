/* 1. Insert a node at the head of a singly linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertHead(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertHead(&head, 3);
    insertHead(&head, 2);
    insertHead(&head, 1);
    printList(head);
    return 0;
}
