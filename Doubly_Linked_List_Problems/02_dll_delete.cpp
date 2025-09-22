/* 47. Delete from a doubly linked list */

#include <iostream>
using namespace std;

struct Node{
    int data; Node* next; Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};

Node* deleteNode(Node* head,int pos){
    if(!head) return nullptr;
    Node* cur=head;
    if(pos==1){ head=head->next; if(head) head->prev=nullptr; delete cur; return head; }
    for(int i=1;i<pos && cur;i++) cur=cur->next;
    if(!cur) return head;
    if(cur->prev) cur->prev->next=cur->next;
    if(cur->next) cur->next->prev=cur->prev;
    delete cur;
    return head;
}

void printList(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; } cout<<endl;
}

int main(){
    Node* head=new Node(10); head->next=new Node(20); head->next->prev=head;
    head->next->next=new Node(30); head->next->next->prev=head->next;
    head=deleteNode(head,2);
    printList(head);
}
