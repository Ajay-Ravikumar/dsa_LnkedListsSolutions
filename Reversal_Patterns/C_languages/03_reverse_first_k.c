/* 13. Reverse first k nodes of a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* reverseK(struct Node* head,int k){
    struct Node* prev=NULL; struct Node* curr=head; struct Node* next=NULL;
    int count=0;
    while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    head->next = curr;
    return prev;
}

void printList(struct Node* h){ while(h){printf("%d->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=newNode(4);
    printf("Original: "); printList(head);
    head = reverseK(head,2);
    printf("Reversed first 2: "); printList(head);
}
