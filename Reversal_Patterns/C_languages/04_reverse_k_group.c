/* 14. Reverse nodes in groups of k (LeetCode 25: Reverse Nodes in k-Group) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverseKGroup(struct Node* head,int k){
    struct Node* curr=head; int count=0;
    while(curr && count<k){ curr=curr->next; count++; }
    if(count<k) return head;
    curr=head; struct Node* prev=NULL; struct Node* next=NULL; count=0;
    while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    if(next) head->next = reverseKGroup(next,k);
    return prev;
}

void printList(struct Node* h){ while(h){printf("%d->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    printf("Original: "); printList(head);
    head = reverseKGroup(head,2);
    printf("Reversed in k=2 groups: "); printList(head);
}
