/* 24. Detect if a circular linked list is circular from start */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

int isCircular(struct Node* head){
    if(!head) return 0;
    struct Node* temp=head->next;
    while(temp && temp!=head) temp=temp->next;
    return temp==head;
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=head;
    printf("Is circular? %s\n", isCircular(head)?"Yes":"No");
}
