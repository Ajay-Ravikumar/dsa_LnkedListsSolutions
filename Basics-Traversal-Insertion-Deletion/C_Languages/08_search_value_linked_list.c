/* 8. Search for a value in a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int search(struct Node* head, int key) {
    while (head) {
        if (head->data == key) return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;

    printf("Search 2: %s\n", search(head, 2) ? "Found" : "Not Found");
    printf("Search 5: %s\n", search(head, 5) ? "Found" : "Not Found");
    return 0;
}
