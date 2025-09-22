/* 41. Flatten a linked list where every node has a child linked list (GFG classic) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node* child; Node(int d):data(d),next(nullptr),child(nullptr){} };

Node* flatten(Node* head){
    if(!head) return nullptr;
    Node* cur=head;
    while(cur){
        if(cur->child){
            Node* temp=cur->next;
            cur->next=flatten(cur->child); cur->child=nullptr;
            Node* t=cur->next; while(t->next) t=t->next;
            t->next=temp;
        }
        cur=cur->next;
    }
    return head;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3);
    h->next->child=new Node(4); h->next->child->next=new Node(5);
    Node* res=flatten(h);
    printList(res);
}
