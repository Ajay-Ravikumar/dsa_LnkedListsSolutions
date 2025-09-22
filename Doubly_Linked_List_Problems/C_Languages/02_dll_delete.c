/* 47. Delete from a doubly linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; return n; }

struct Node* deleteNode(struct Node* head,int pos){
    if(!head) return NULL;
    struct Node* cur=head;
    if(pos==1){ head=head->next; if(head) head->prev=NULL; free(cur); return head; }
    for(int i=1;i<pos && cur;i++) cur=cur->next;
    if(!cur) return head;
    if(cur->prev) cur->prev->next=cur->next;
    if(cur->next) cur->next->prev=cur->prev;
    free(cur);
    return head;
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next; } printf("\n"); }

int main(){
    struct Node* head=newNode(10); head->next=newNode(20); head->next->prev=head;
    head->next->next=newNode(30); head->next->next->prev=head->next;
    head=deleteNode(head,2);
    printList(head);
}
