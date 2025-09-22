/* 40. Flatten a multilevel doubly linked list (LeetCode 430) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; struct Node* child; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; n->child=NULL; return n; }

struct Node* flatten(struct Node* head){
    if(!head) return NULL;
    struct Node* cur=head;
    while(cur){
        if(cur->child){
            struct Node* child=flatten(cur->child);
            struct Node* next=cur->next;
            cur->next=child; if(child) child->prev=cur; cur->child=NULL;
            while(cur->next) cur=cur->next;
            cur->next=next; if(next) next->prev=cur;
        }
        cur=cur->next;
    }
    return head;
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next; } printf("\n"); }

int main(){
    struct Node* n1=newNode(1); struct Node* n2=newNode(2); struct Node* n3=newNode(3);
    n1->next=n2; n2->prev=n1; n2->next=n3; n3->prev=n2;
    struct Node* c1=newNode(4); struct Node* c2=newNode(5);
    n2->child=c1; c1->next=c2; c2->prev=c1;
    struct Node* res=flatten(n1);
    printList(res);
}
