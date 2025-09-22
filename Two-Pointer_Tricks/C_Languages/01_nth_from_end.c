/* 26. Find nth node from the end (single pass, two pointers) */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d; n->next = NULL; return n;
}

struct Node* nthFromEnd(struct Node* head, int n) {
    struct Node *first=head, *second=head;
    for(int i=0;i<n;i++){ if(!first) return NULL; first=first->next; }
    while(first){ first=first->next; second=second->next; }
    return second;
}

int main() {
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3);
    struct Node* res=nthFromEnd(head,2);
    if(res) printf("Nth from end: %d\n",res->data);
    else printf("Not enough nodes\n");
}
