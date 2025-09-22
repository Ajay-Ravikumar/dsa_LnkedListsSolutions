/* 40. Flatten a multilevel doubly linked list (LeetCode 430) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node* prev; Node* child; Node(int d):data(d),next(nullptr),prev(nullptr),child(nullptr){} };

Node* flatten(Node* head){
    if(!head) return nullptr;
    Node* cur=head;
    while(cur){
        if(cur->child){
            Node* child=flatten(cur->child);
            Node* next=cur->next;
            cur->next=child; child->prev=cur; cur->child=nullptr;
            while(cur->next) cur=cur->next;
            cur->next=next; if(next) next->prev=cur;
        }
        cur=cur->next;
    }
    return head;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* n1=new Node(1); Node* n2=new Node(2); Node* n3=new Node(3);
    n1->next=n2; n2->prev=n1; n2->next=n3; n3->prev=n2;
    Node* c1=new Node(4); Node* c2=new Node(5);
    n2->child=c1; c1->next=c2; c2->prev=c1;
    Node* res=flatten(n1);
    printList(res);
}
