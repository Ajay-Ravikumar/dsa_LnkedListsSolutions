/* 46. Insert into a doubly linked list (front, end, middle) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; return n; }

struct Node* insertFront(struct Node* head,int val){
    struct Node* n=newNode(val); n->next=head;
    if(head) head->prev=n;
    return n;
}

struct Node* insertEnd(struct Node* head,int val){
    struct Node* n=newNode(val);
    if(!head) return n;
    struct Node* cur=head;
    while(cur->next) cur=cur->next;
    cur->next=n; n->prev=cur;
    return head;
}

struct Node* insertAtPos(struct Node* head,int pos,int val){
    if(pos==1) return insertFront(head,val);
    struct Node* cur=head;
    for(int i=1;i<pos-1 && cur;i++) cur=cur->next;
    if(!cur) return head;
    struct Node* n=newNode(val);
    n->next=cur->next; if(cur->next) cur->next->prev=n;
    cur->next=n; n->prev=cur;
    return head;
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next; } printf("\n"); }

int main(){
    struct Node* head=NULL;
    head=insertFront(head,10);
    head=insertEnd(head,20);
    head=insertAtPos(head,2,15);
    printList(head);
}
