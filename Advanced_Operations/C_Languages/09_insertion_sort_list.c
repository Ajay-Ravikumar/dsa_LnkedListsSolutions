/* 44. Sort a linked list using insertion sort (LeetCode 147) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* insertionSortList(struct Node* head){
    struct Node dummy={0,NULL};
    struct Node* cur=head;
    while(cur){
        struct Node* next=cur->next;
        struct Node* prev=&dummy;
        while(prev->next && prev->next->data<cur->data) prev=prev->next;
        cur->next=prev->next; prev->next=cur;
        cur=next;
    }
    return dummy.next;
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next; } printf("\n"); }

int main(){
    struct Node* h=newNode(4); h->next=newNode(2); h->next->next=newNode(1); h->next->next->next=newNode(3);
    struct Node* res=insertionSortList(h);
    printList(res);
}
