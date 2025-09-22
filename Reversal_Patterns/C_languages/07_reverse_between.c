/* 17. Reverse only the sublist between positions m and n (LeetCode 92: Reverse Linked List II) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverseBetween(struct Node* head,int m,int n){
    if(!head) return NULL;
    struct Node dummy; dummy.next=head; struct Node* prev=&dummy;
    for(int i=1;i<m;i++) prev=prev->next;
    struct Node* curr=prev->next;
    for(int i=0;i<n-m;i++){
        struct Node* temp=curr->next;
        curr->next=temp->next;
        temp->next=prev->next;
        prev->next=temp;
    }
    return dummy.next;
}

void printList(struct Node* h){ while(h){printf("%d->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=newNode(4); head->next->next->next->next=newNode(5);
    printf("Original: "); printList(head);
    head=reverseBetween(head,2,4);
    printf("Reverse 2-4: "); printList(head);
}
