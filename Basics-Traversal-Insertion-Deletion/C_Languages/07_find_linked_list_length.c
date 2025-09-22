/* 7. Find the length of a linked list (iterative + recursive) */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int lengthIter(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int lengthRec(struct Node* head) {
    return head ? 1 + lengthRec(head->next) : 0;
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;

    printf("Length (iter): %d\n", lengthIter(head));
    printf("Length (rec): %d\n", lengthRec(head));
    return 0;
}
