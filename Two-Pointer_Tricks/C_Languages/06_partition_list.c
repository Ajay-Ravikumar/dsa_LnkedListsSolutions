/* 31. Partition linked list around a value x (LeetCode 86) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};
struct Node* newNode(int d){struct Node* n=malloc(sizeof(struct Node));n->data=d;n->next=NULL;return n;}

struct Node* partition(struct Node* head,int x){
    struct Node lessDummy={0,NULL},greaterDummy={0,NULL};
    struct Node *less=&lessDummy,*greater=&greaterDummy;
    while(head){
        if(head->data<x){ less->next=head; less=less->next; }
        else{ greater->next=head; greater=greater->next; }
        head=head->next;
    }
    greater->next=NULL; less->next=greaterDummy.next;
    return lessDummy.next;
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next;} printf("\n"); }

int main(){
    struct Node* h=newNode(3); h->next=newNode(5); h->next->next=newNode(2); h->next->next->next=newNode(4);
    h=partition(h,3); printList(h);
}
