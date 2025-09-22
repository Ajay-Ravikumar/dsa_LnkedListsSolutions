/* 37. Add two numbers (digits stored in forward order – LeetCode 445) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* reverse(struct Node* head){
    struct Node* prev=NULL,*cur=head;
    while(cur){ struct Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2){
    l1=reverse(l1); l2=reverse(l2);
    struct Node dummy={0,NULL}; struct Node* curr=&dummy;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=carry + (l1?l1->data:0) + (l2?l2->data:0);
        carry=sum/10;
        curr->next=newNode(sum%10); curr=curr->next;
        if(l1) l1=l1->next; if(l2) l2=l2->next;
    }
    return reverse(dummy.next);
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next; } printf("\n"); }

int main(){
    struct Node* a=newNode(7); a->next=newNode(2); a->next->next=newNode(4); a->next->next->next=newNode(3);
    struct Node* b=newNode(5); b->next=newNode(6); b->next->next=newNode(4);
    struct Node* res=addTwoNumbers(a,b);
    printList(res);
}
