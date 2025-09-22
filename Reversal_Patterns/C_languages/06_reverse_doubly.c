/* 16. Reverse a doubly linked list */

#include <stdio.h>
#include <stdlib.h>

struct DNode{int data; struct DNode* prev; struct DNode* next;};

struct DNode* newNode(int d){ struct DNode* n=malloc(sizeof(struct DNode)); n->data=d; n->prev=n->next=NULL; return n;}

struct DNode* reverseDLL(struct DNode* head){
    struct DNode* temp=NULL,*curr=head;
    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp) head=temp->prev;
    return head;
}

void printList(struct DNode* h){ while(h){printf("%d<->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct DNode* head=newNode(1); head->next=newNode(2); head->next->prev=head; head->next->next=newNode(3); head->next->next->prev=head->next;
    printf("Original: "); printList(head);
    head = reverseDLL(head);
    printf("Reversed: "); printList(head);
}
