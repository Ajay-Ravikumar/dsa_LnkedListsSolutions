/* 43. Sort a linked list using merge sort (LeetCode 148) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* merge(struct Node* a, struct Node* b){
    struct Node dummy={0,NULL}; struct Node* tail=&dummy;
    while(a && b){
        if(a->data<b->data){ tail->next=a; a=a->next; }
        else{ tail->next=b; b=b->next; }
        tail=tail->next;
    }
    tail->next=(a?a:b);
    return dummy.next;
}

struct Node* mergeSort(struct Node* head){
    if(!head || !head->next) return head;
    struct Node* slow=head; struct Node* fast=head; struct Node* prev=NULL;
    while(fast && fast->next){ prev=slow; slow=slow->next; fast=fast->next->next; }
    prev->next=NULL;
    struct Node* l1=mergeSort(head); struct Node* l2=mergeSort(slow);
    return merge(l1,l2);
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next; } printf("\n"); }

int main(){
    struct Node* h=newNode(4); h->next=newNode(2); h->next->next=newNode(1); h->next->next->next=newNode(3);
    struct Node* res=mergeSort(h); printList(res);
}
