/* 6. Delete a node at a given position */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) return;
    if (pos == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp && i < pos-1; i++) temp = temp->next;
    if (!temp || !temp->next) return;
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
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
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Before: "); printList(head);
    deleteAtPos(&head, 2);
    printf("After: "); printList(head);
    return 0;
}
