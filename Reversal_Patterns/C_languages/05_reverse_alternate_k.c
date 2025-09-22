/* 15. Reverse alternate k nodes in a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverseAltK(struct Node* head,int k,int rev){
    if(!head) return NULL;
    struct Node* curr=head,*prev=NULL,*next=NULL; int count=0;
    if(rev){
        while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
        head->next = reverseAltK(curr,k,!rev);
        return prev;
    } else {
        while(curr && count<k-1){ curr=curr->next; count++; }
        if(curr) curr->next = reverseAltK(curr->next,k,!rev);
        return head;
    }
}

void printList(struct Node* h){ while(h){printf("%d->",h->data); h=h->next;} printf("NULL\n"); }

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3);
    head->next->next->next=newNode(4); head->next->next->next->next=newNode(5);
    printf("Original: "); printList(head);
    head = reverseAltK(head,2,1);
    printf("Reversed alternate k=2: "); printList(head);
}
