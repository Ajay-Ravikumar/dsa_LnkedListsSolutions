/* 20. Check if a linked list is palindrome (reverse second half + compare) */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n;}

struct Node* reverse(struct Node* head){ struct Node* prev=NULL,*curr=head,*next; while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; } return prev; }

int isPalindrome(struct Node* head){
    if(!head||!head->next) return 1;
    struct Node* slow=head,*fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    struct Node* second=reverse(slow->next);
    struct Node* first=head; struct Node* copy=second;
    while(second){ if(first->data!=second->data) return 0; first=first->next; second=second->next; }
    reverse(copy);
    return 1;
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(2); head->next->next->next=newNode(1);
    printf("Palindrome? %s\n", isPalindrome(head)?"Yes":"No");
}
