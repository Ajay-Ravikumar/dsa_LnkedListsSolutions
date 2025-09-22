/* 4. Delete a node at the head of a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteHead(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1; head->next = malloc(sizeof(struct Node));
    head->next->data = 2; head->next->next = NULL;

    printf("Before: "); printList(head);
    deleteHead(&head);
    printf("After: "); printList(head);
    return 0;
}
