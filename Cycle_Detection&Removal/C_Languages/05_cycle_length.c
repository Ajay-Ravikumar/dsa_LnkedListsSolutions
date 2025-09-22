/* 25. Length of cycle in a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data; struct Node* next;};

struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

int cycleLength(struct Node* head){
    struct Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast){
            int len=1; fast=fast->next;
            while(slow!=fast){ len++; fast=fast->next; }
            return len;
        }
    }
    return 0;
}

int main(){
    struct Node* head=newNode(1); head->next=newNode(2); head->next->next=newNode(3); head->next->next->next=head->next;
    printf("Cycle length: %d\n", cycleLength(head));
}
