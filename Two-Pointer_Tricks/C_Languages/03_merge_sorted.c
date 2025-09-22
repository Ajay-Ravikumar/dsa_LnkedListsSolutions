/* 28. Merge two sorted linked lists (LeetCode 21) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* merge(struct Node* l1,struct Node* l2){
    if(!l1) return l2; if(!l2) return l1;
    if(l1->data<l2->data){ l1->next=merge(l1->next,l2); return l1;}
    else{ l2->next=merge(l1,l2->next); return l2;}
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next;} printf("\n"); }

int main(){
    struct Node* a=newNode(1); a->next=newNode(3); a->next->next=newNode(5);
    struct Node* b=newNode(2); b->next=newNode(4);
    struct Node* res=merge(a,b); printList(res);
}
