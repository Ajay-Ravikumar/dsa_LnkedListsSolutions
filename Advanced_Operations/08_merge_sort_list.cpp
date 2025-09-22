/* 43. Sort a linked list using merge sort (LeetCode 148) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* merge(Node* a, Node* b){
    Node dummy(0); Node* tail=&dummy;
    while(a && b){
        if(a->data<b->data){ tail->next=a; a=a->next; }
        else { tail->next=b; b=b->next; }
        tail=tail->next;
    }
    tail->next=(a?a:b);
    return dummy.next;
}

Node* mergeSort(Node* head){
    if(!head || !head->next) return head;
    Node* slow=head; Node* fast=head; Node* prev=nullptr;
    while(fast && fast->next){ prev=slow; slow=slow->next; fast=fast->next->next; }
    prev->next=nullptr;
    Node* l1=mergeSort(head); Node* l2=mergeSort(slow);
    return merge(l1,l2);
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }

int main(){
    Node* h=new Node(4); h->next=new Node(2); h->next->next=new Node(1); h->next->next->next=new Node(3);
    Node* res=mergeSort(h); printList(res);
}
