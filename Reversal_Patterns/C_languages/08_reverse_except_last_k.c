/* 18. Reverse the entire list except for last k nodes */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverseExceptLastK(struct Node* head,int k){
    int len=0; struct Node* temp=head;
    while(temp){ len++; temp=temp->next; }
    int n=len-k; if(n<=0) return head;
    struct Node *prev=NULL,*curr=head,*next=NULL;
    int count=0;
    while(curr && count<n){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    head->next=curr;
    return prev;
}

void printList(struct Node* h){ while(h){printf("%d->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=newNode(4); head->next->next->next->next=newNode(5);
    printf("Original: "); printList(head);
    head=reverseExceptLastK(head,2);
    printf("Reversed except last 2: "); printList(head);
}
