/* 31. Partition linked list around a value x (LeetCode 86) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* partition(Node* head,int x){
    Node lessDummy(0), greaterDummy(0);
    Node *less=&lessDummy,*greater=&greaterDummy;
    while(head){
        if(head->data<x){ less->next=head; less=less->next; }
        else{ greater->next=head; greater=greater->next; }
        head=head->next;
    }
    greater->next=nullptr; less->next=greaterDummy.next;
    return lessDummy.next;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* h=new Node(3); h->next=new Node(5); h->next->next=new Node(2); h->next->next->next=new Node(4);
    h=partition(h,3); printList(h);
}
