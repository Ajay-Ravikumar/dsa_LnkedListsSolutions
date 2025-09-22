/* 9. Print a linked list in reverse (without modifying it) */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printReverse(struct Node* head) {
    if (head == NULL) return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Reverse print: ");
    printReverse(head);
    printf("\n");
    return 0;
}
