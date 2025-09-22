/* 3. Insert a node at a given position (1-based index) */

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

void insertAtPos(struct Node** head, int data, int pos) {
    if (pos == 1) {
        struct Node* node = newNode(data);
        node->next = *head;
        *head = node;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp && i < pos-1; i++) temp = temp->next;
    if (!temp) return;
    struct Node* node = newNode(data);
    node->next = temp->next;
    temp->next = node;
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
    insertAtPos(&head, 1, 1);
    insertAtPos(&head, 2, 2);
    insertAtPos(&head, 3, 3);
    insertAtPos(&head, 99, 2);
    printList(head);
    return 0;
}
