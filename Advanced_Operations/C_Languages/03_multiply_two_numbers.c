/* 38. Multiply two numbers represented by linked lists */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node* next; };
struct Node* newNode(int d){ struct Node* n=malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* multiplyTwoNumbers(struct Node* l1, struct Node* l2){
    int num1[100],num2[100]; int n1=0,n2=0;
    while(l1){ num1[n1++]=l1->data; l1=l1->next; }
    while(l2){ num2[n2++]=l2->data; l2=l2->next; }
    int result[200]={0};
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++) result[i+j]+=num1[i]*num2[j];
    int carry=0; struct Node* head=NULL; struct Node* tail=NULL;
    for(int i=0;i<n1+n2;i++){
        int sum=result[i]+carry; carry=sum/10; sum=sum%10;
        struct Node* n=newNode(sum);
        if(!head){ head=tail=n; } else { tail->next=n; tail=n; }
    }
    while(head && head->next && head->data==0){ struct Node* tmp=head; head=head->next; free(tmp); }
    return head;
}

void printList(struct Node* head){ while(head){ printf("%d ",head->data); head=head->next; } printf("\n"); }

int main(){
    struct Node* a=newNode(3); a->next=newNode(4); a->next->next=newNode(2);
    struct Node* b=newNode(4); b->next=newNode(6); b->next->next=newNode(5);
    struct Node* res=multiplyTwoNumbers(a,b);
    printList(res);
}
