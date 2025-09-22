/* 50. Check if a doubly linked list is palindrome */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* prev; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->prev=NULL; return n; }

int isPalindrome(struct Node* head){
    if(!head) return 1;
    struct Node* start=head; struct Node* end=head;
    while(end->next) end=end->next;
    while(start!=end && end->next!=start){
        if(start->data!=end->data) return 0;
        start=start->next; end=end->prev;
    }
    return 1;
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->prev=head;
    head->next->next=newNode(2); head->next->next->prev=head->next;
    head->next->next->next=newNode(1); head->next->next->next->prev=head->next->next;
    printf("Is palindrome? %s\n",isPalindrome(head)?"Yes":"No");
}
