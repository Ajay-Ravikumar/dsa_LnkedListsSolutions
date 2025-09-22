/* 48. Find pairs with given sum in a sorted doubly linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; return n; }

void findPairs(struct Node* head,int sum){
    struct Node* start=head; struct Node* end=head;
    while(end->next) end=end->next;
    while(start && end && start!=end && end->next!=start){
        int s=start->data + end->data;
        if(s==sum){ printf("(%d,%d) ",start->data,end->data); start=start->next; end=end->prev; }
        else if(s<sum) start=start->next;
        else end=end->prev;
    }
    printf("\n");
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->prev=head;
    head->next->next=newNode(4); head->next->next->prev=head->next;
    head->next->next->next=newNode(5); head->next->next->next->prev=head->next->next;
    findPairs(head,6);
}
