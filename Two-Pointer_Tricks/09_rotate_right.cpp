/* 34. Rotate linked list to the right by k places (LeetCode 61) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* rotateRight(Node* head,int k){
    if(!head||!head->next||k==0) return head;
    Node* cur=head; int len=1;
    while(cur->next){ cur=cur->next; len++; }
    cur->next=head; k%=len; int steps=len-k;
    Node* newTail=head;
    for(int i=1;i<steps;i++) newTail=newTail->next;
    Node* newHead=newTail->next; newTail->next=nullptr;
    return newHead;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4);
    h=rotateRight(h,2); printList(h);
}
