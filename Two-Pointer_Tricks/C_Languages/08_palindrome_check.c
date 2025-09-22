/* 33. Check if linked list is palindrome (two-pointer method) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node* next;};
struct Node* newNode(int d){struct Node* n=malloc(sizeof(struct Node));n->data=d;n->next=NULL;return n;}

struct Node* reverse(struct Node* h){
    struct Node* prev=NULL,*cur=h;
    while(cur){ struct Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

int isPalindrome(struct Node* head){
    if(!head||!head->next) return 1;
    struct Node* slow=head,*fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    struct Node* second=reverse(slow->next); struct Node* p1=head,*p2=second;
    while(p2){ if(p1->data!=p2->data) return 0; p1=p1->next; p2=p2->next; }
    return 1;
}

int main(){
    struct Node* h=newNode(1); h->next=newNode(2); h->next->next=newNode(2); h->next->next->next=newNode(1);
    printf("Is palindrome? %s\n",isPalindrome(h)?"Yes":"No");
}
