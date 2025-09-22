/* 13. Reverse first k nodes of a linked list */

#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* reverseFirstK(Node* head,int k){
    Node* prev=nullptr,*curr=head,*next=nullptr; int count=0;
    while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    head->next = curr;
    return prev;
}

void printList(Node* h){ while(h){ cout<<h->data<<"->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4);
    cout<<"Original: "; printList(head);
    head=reverseFirstK(head,2);
    cout<<"Reversed first 2: "; printList(head);
}
