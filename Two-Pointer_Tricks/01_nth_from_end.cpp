/* 26. Find nth node from the end (single pass, two pointers) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* nthFromEnd(Node* head,int n){
    Node *first=head,*second=head;
    for(int i=0;i<n;i++) if(first) first=first->next; else return nullptr;
    while(first){ first=first->next; second=second->next; }
    return second;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3);
    Node* res=nthFromEnd(head,2);
    if(res) cout<<"Nth from end: "<<res->data<<endl;
    else cout<<"Not enough nodes\n";
}
