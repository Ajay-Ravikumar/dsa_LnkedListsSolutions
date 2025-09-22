/* 32. Swap kth node from beginning with kth node from end */

#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node* next;};
struct Node* newNode(int d){struct Node* n=malloc(sizeof(struct Node));n->data=d;n->next=NULL;return n;}

int length(struct Node* h){int c=0;while(h){c++;h=h->next;}return c;}

void swapKth(struct Node* head,int k){
    int n=length(head); if(k>n) return;
    struct Node* x=head; for(int i=1;i<k;i++) x=x->next;
    struct Node* y=head; for(int i=1;i<n-k+1;i++) y=y->next;
    int temp=x->data; x->data=y->data; y->data=temp;
}

void printList(struct Node* h){while(h){printf("%d ",h->data);h=h->next;}printf("\n");}

int main(){
    struct Node* h=newNode(1); h->next=newNode(2); h->next->next=newNode(3); h->next->next->next=newNode(4);
    swapKth(h,2); printList(h);
}
