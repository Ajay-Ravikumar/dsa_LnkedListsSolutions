/* 27. Delete nth node from the end (LeetCode 19) */

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* deleteNthFromEnd(struct Node* head,int n){
    struct Node dummy={0,head};
    struct Node *first=&dummy,*second=&dummy;
    for(int i=0;i<=n;i++){ if(!first) return head; first=first->next; }
    while(first){ first=first->next; second=second->next; }
    struct Node* del=second->next; second->next=del->next; free(del);
    return dummy.next;
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next;} printf("\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=newNode(4);
    head=deleteNthFromEnd(head,2);
    printList(head);
}
