/* 21. Detect if a cycle exists (Floyd’s Cycle Detection – tortoise and hare) */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d; n->next = NULL; return n;
}

int hasCycle(struct Node* head){
    struct Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}

int main(){
    struct Node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=head; // cycle
    printf("Has cycle? %s\n", hasCycle(head)?"Yes":"No");
}
