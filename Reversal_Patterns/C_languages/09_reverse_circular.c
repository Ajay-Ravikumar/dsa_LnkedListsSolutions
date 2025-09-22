/* 19. Reverse a circular linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverseCircular(struct Node* head){
    if(!head||head->next==head) return head;
    struct Node *prev=NULL,*curr=head,*next=NULL; struct Node* tail=head;
    do{ next=curr->next; curr->next=prev; prev=curr; curr=next; }while(curr!=head);
    head->next=prev; head=prev;
    return head;
}

void printCirc(struct Node* head){
    if(!head) return;
    struct Node* temp=head;
    do{ printf("%d->",temp->data); temp=temp->next; }while(temp!=head);
    printf("(back to head)\n");
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=head;
    printf("Original: "); printCirc(head);
    head=reverseCircular(head);
    printf("Reversed circular: "); printCirc(head);
}
