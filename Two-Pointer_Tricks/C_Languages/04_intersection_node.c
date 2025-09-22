/* 29. Find intersection node of two linked lists (LeetCode 160) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

int getLength(struct Node* head){int len=0; while(head){len++; head=head->next;} return len;}

struct Node* getIntersection(struct Node* a,struct Node* b){
    int lenA=getLength(a),lenB=getLength(b);
    while(lenA>lenB){ a=a->next; lenA--; }
    while(lenB>lenA){ b=b->next; lenB--; }
    while(a && b){ if(a==b) return a; a=a->next; b=b->next; }
    return NULL;
}

int main(){
    struct Node* common=malloc(sizeof(struct Node)); common->data=8; common->next=NULL;
    struct Node* a=malloc(sizeof(struct Node)); a->data=1; a->next=common;
    struct Node* b=malloc(sizeof(struct Node)); b->data=2; b->next=common;
    struct Node* res=getIntersection(a,b);
    if(res) printf("Intersection at %d\n",res->data); else printf("No intersection\n");
}
