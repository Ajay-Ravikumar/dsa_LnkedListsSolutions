/* 42. Merge K sorted linked lists (LeetCode 23 – using min-heap) */
 
#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* mergeTwo(struct Node* a, struct Node* b){
    struct Node dummy={0,NULL}; struct Node* tail=&dummy;
    while(a && b){
        if(a->data<b->data){ tail->next=a; a=a->next; } 
        else { tail->next=b; b=b->next; }
        tail=tail->next;
    }
    tail->next=(a?a:b);
    return dummy.next;
}

struct Node* mergeKLists(struct Node* lists[], int n){
    if(n==0) return NULL;
    while(n>1){
        int i,j=0;
        for(i=0;i<n;i+=2){
            if(i+1<n) lists[j++]=mergeTwo(lists[i],lists[i+1]);
            else lists[j++]=lists[i];
        }
        n=j;
    }
    return lists[0];
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next;} printf("\n"); }

int main(){
    struct Node* a=newNode(1); a->next=newNode(4); a->next->next=newNode(5);
    struct Node* b=newNode(1); b->next=newNode(3); b->next->next=newNode(4);
    struct Node* c=newNode(2); c->next=newNode(6);
    struct Node* lists[]={a,b,c};
    struct Node* res=mergeKLists(lists,3);
    printList(res);
}
