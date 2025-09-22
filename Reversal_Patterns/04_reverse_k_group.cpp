/* 14. Reverse nodes in groups of k (LeetCode 25: Reverse Nodes in k-Group) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverseKGroup(Node* head,int k){
    Node* curr=head; int count=0;
    while(curr && count<k){ curr=curr->next; count++; }
    if(count<k) return head;
    curr=head; Node* prev=nullptr,*next=nullptr; count=0;
    while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    if(next) head->next=reverseKGroup(next,k);
    return prev;
}

void printList(Node* h){ while(h){ cout<<h->data<<"->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5);
    cout<<"Original: "; printList(head);
    head=reverseKGroup(head,2);
    cout<<"Reversed in groups of 2: "; printList(head);
}
