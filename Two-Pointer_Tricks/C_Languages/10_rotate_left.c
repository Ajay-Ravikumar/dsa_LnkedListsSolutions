/* 35. Rotate linked list to the left by k places */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node* next;};
struct Node* newNode(int d){struct Node* n=malloc(sizeof(struct Node));n->data=d;n->next=NULL;return n;}

struct Node* rotateLeft(struct Node* head,int k){
    if(!head||!head->next||k==0) return head;
    struct Node* cur=head; int len=1;
    while(cur->next){ cur=cur->next; len++; }
    cur->next=head; k=k%len; int steps=k;
    struct Node* newTail=head;
    for(int i=1;i<steps;i++) newTail=newTail->next;
    struct Node* newHead=newTail->next; newTail->next=NULL;
    return newHead;
}

void printList(struct Node* h){while(h){printf("%d ",h->data);h=h->next;}printf("\n");}

int main(){
    struct Node* h=newNode(1); h->next=newNode(2); h->next->next=newNode(3); h->next->next->next=newNode(4);
    h=rotateLeft(h,2); printList(h);
}
