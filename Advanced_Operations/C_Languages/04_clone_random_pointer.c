#include <stdio.h>
#include <stdlib.h>
/* 39. Clone a linked list with random pointers (LeetCode 138) */

#include <string.h>

struct Node{ int data; struct Node* next; struct Node* random; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->random=NULL; return n; }

struct Node* cloneList(struct Node* head){
    if(!head) return NULL;
    struct Node* cur=head;
    // Step1: insert cloned nodes
    while(cur){
        struct Node* n=newNode(cur->data);
        n->next=cur->next; cur->next=n; cur=n->next;
    }
    // Step2: assign random
    cur=head;
    while(cur){
        if(cur->random) cur->next->random=cur->random->next;
        cur=cur->next->next;
    }
    // Step3: separate lists
    struct Node* dummy=NULL; struct Node* cloneHead=head->next; struct Node* cloneCur=cloneHead;
    cur=head;
    while(cur){
        cur->next=cur->next->next;
        if(cloneCur->next) cloneCur->next=cloneCur->next->next;
        cur=cur->next; cloneCur=cloneCur->next;
    }
    return cloneHead;
}

void printList(struct Node* h){ while(h){ printf("[%d,%d] ", h->data,h->random?h->random->data:-1); h=h->next; } printf("\n"); }

int main(){
    struct Node* n1=newNode(1); struct Node* n2=newNode(2); struct Node* n3=newNode(3);
    n1->next=n2; n2->next=n3; n1->random=n3; n2->random=n1; n3->random=n2;
    struct Node* cloned=cloneList(n1);
    printList(cloned);
}
