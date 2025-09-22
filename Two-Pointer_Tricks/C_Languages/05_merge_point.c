/* 30. Find if two linked lists merge and return merge point */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

int getMergePoint(struct Node* a,struct Node* b){
    struct Node* p=a,*q=b;
    while(p!=q){ p=p?p->next:b; q=q?q->next:a; }
    return p?p->data:-1;
}

int main(){
    struct Node* common=malloc(sizeof(struct Node)); common->data=99; common->next=NULL;
    struct Node* a=malloc(sizeof(struct Node)); a->data=1; a->next=common;
    struct Node* b=malloc(sizeof(struct Node)); b->data=2; b->next=common;
    printf("Merge point: %d\n",getMergePoint(a,b));
}
