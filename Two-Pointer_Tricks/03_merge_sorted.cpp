/* 28. Merge two sorted linked lists (LeetCode 21) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* merge(Node* l1,Node* l2){
    if(!l1) return l2; if(!l2) return l1;
    if(l1->data<l2->data){ l1->next=merge(l1->next,l2); return l1;}
    else{ l2->next=merge(l1,l2->next); return l2;}
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* a=new Node(1); a->next=new Node(3); a->next->next=new Node(5);
    Node* b=new Node(2); b->next=new Node(4);
    Node* res=merge(a,b); printList(res);
}
