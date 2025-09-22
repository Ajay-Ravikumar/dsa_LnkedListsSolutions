/* 41. Flatten a linked list where every node has a child linked list (GFG classic) */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; struct Node* child; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->child=NULL; return n; }

struct Node* flatten(struct Node* head){
    if(!head) return NULL;
    struct Node* cur=head;
    while(cur){
        if(cur->child){
            struct Node* temp=cur->next;
            cur->next=flatten(cur->child);
            cur->child=NULL;
            struct Node* t=cur->next;
            while(t->next) t=t->next;
            t->next=temp;
        }
        cur=cur->next;
    }
    return head;
}

void printList(struct Node* h){ while(h){ printf("%d ",h->data); h=h->next; } printf("\n"); }

int main(){
    struct Node* h=newNode(1); h->next=newNode(2); h->next->next=newNode(3);
    h->next->child=newNode(4); h->next->child->next=newNode(5);
    struct Node* res=flatten(h);
    printList(res);
}
