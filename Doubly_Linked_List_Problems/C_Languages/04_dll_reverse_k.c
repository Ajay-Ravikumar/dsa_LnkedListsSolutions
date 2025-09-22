/* 49. Reverse a doubly linked list in groups of k */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; return n; }

struct Node* reverseK(struct Node* head,int k){
    struct Node* cur=head; struct Node* newHead=NULL; struct Node* ktail=NULL;
    while(cur){
        int count=0; struct Node* temp=cur; struct Node* prev=NULL;
        while(temp && count<k){
            struct Node* nxt=temp->next;
            temp->next=prev; temp->prev=nxt;
            prev=temp; temp=nxt; count++;
        }
        if(!newHead) newHead=prev;
        if(ktail) ktail->next=prev;
        ktail=cur;
        cur=temp;
    }
    return newHead;
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next; } printf("\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->prev=head;
    head->next->next=newNode(3); head->next->next->prev=head->next;
    head->next->next->next=newNode(4); head->next->next->next->prev=head->next->next;
    head->next->next->next->next=newNode(5); head->next->next->next->next->prev=head->next->next->next;
    head=reverseK(head,2);
    printList(head);
}
