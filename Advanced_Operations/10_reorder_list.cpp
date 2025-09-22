/* 45. Reorder list (LeetCode 143) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* reverse(Node* head){
    Node* prev=nullptr,*cur=head;
    while(cur){ Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

void reorderList(Node* head){
    if(!head || !head->next) return;
    Node* slow=head,*fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    Node* l2=reverse(slow->next); slow->next=nullptr;
    Node* l1=head;
    while(l2){
        Node* n1=l1->next; Node* n2=l2->next;
        l1->next=l2; l2->next=n1;
        l1=n1; l2=n2;
    }
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4);
    reorderList(h); printList(h); // Expected 1 4 2 3
}
