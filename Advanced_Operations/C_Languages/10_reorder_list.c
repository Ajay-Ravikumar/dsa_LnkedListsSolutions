/* 45. Reorder list (LeetCode 143) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* reverse(struct Node* head){
    struct Node* prev=NULL; struct Node* cur=head;
    while(cur){ struct Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

void reorderList(struct Node* head){
    if(!head || !head->next) return;
    struct Node* slow=head; struct Node* fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    struct Node* l2=reverse(slow->next); slow->next=NULL;
    struct Node* l1=head;
    while(l2){
        struct Node* n1=l1->next; struct Node* n2=l2->next;
        l1->next=l2; l2->next=n1;
        l1=n1; l2=n2;
    }
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next;} printf("\n"); }

int main(){
    struct Node* h=newNode(1); h->next=newNode(2); h->next->next=newNode(3); h->next->next->next=newNode(4);
    reorderList(h);
    printList(h);
}
