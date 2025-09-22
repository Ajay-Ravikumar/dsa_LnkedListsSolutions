/* 44. Sort a linked list using insertion sort (LeetCode 147) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* insertionSortList(Node* head){
    Node dummy(0);
    while(head){
        Node* temp=head->next; Node* prev=&dummy;
        while(prev->next && prev->next->data<head->data) prev=prev->next;
        head->next=prev->next; prev->next=head;
        head=temp;
    }
    return dummy.next;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }

int main(){
    Node* h=new Node(4); h->next=new Node(2); h->next->next=new Node(1); h->next->next->next=new Node(3);
    Node* res=insertionSortList(h); printList(res);
}
