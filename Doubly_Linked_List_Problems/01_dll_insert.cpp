/* 46. Insert into a doubly linked list (front, end, middle) */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};

Node* insertFront(Node* head,int val){
    Node* n=new Node(val);
    n->next=head;
    if(head) head->prev=n;
    return n;
}

Node* insertEnd(Node* head,int val){
    Node* n=new Node(val);
    if(!head) return n;
    Node* cur=head;
    while(cur->next) cur=cur->next;
    cur->next=n; n->prev=cur;
    return head;
}

Node* insertAtPos(Node* head,int pos,int val){
    if(pos==1) return insertFront(head,val);
    Node* cur=head;
    for(int i=1;i<pos-1 && cur;i++) cur=cur->next;
    if(!cur) return head;
    Node* n=new Node(val);
    n->next=cur->next; if(cur->next) cur->next->prev=n;
    cur->next=n; n->prev=cur;
    return head;
}

void printList(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
    cout<<endl;
}

int main(){
    Node* head=nullptr;
    head=insertFront(head,10);
    head=insertEnd(head,20);
    head=insertAtPos(head,2,15);
    printList(head);
}
