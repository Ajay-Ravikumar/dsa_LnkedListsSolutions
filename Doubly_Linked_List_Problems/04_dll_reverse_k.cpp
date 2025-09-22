/* 49. Reverse a doubly linked list in groups of k */

#include <iostream>
using namespace std;

struct Node{
    int data; Node* next; Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};

Node* reverseK(Node* head,int k){
    Node* cur=head; Node* newHead=nullptr; Node* ktail=nullptr;
    while(cur){
        int count=0; Node* temp=cur; Node* prev=nullptr;
        while(temp && count<k){ Node* nxt=temp->next; temp->next=prev; temp->prev=nxt; prev=temp; temp=nxt; count++; }
        if(!newHead) newHead=prev;
        if(ktail) ktail->next=prev; ktail=cur;
        cur=temp;
    }
    return newHead;
}

void printList(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; } cout<<endl;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->prev=head;
    head->next->next=new Node(3); head->next->next->prev=head->next;
    head->next->next->next=new Node(4); head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new Node(5); head->next->next->next->next->prev=head->next->next->next;
    head=reverseK(head,2);
    printList(head); // Expected 2 1 4 3 5
}
