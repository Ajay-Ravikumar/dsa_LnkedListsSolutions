/* 39. Clone a linked list with random pointers (LeetCode 138) */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{ int data; Node* next; Node* random; Node(int d):data(d),next(nullptr),random(nullptr){} };

Node* cloneList(Node* head){
    if(!head) return nullptr;
    unordered_map<Node*,Node*> m;
    Node* cur=head;
    while(cur){ m[cur]=new Node(cur->data); cur=cur->next; }
    cur=head;
    while(cur){
        m[cur]->next = m[cur->next];
        m[cur]->random = m[cur->random];
        cur=cur->next;
    }
    return m[head];
}

void printList(Node* head){
    while(head){ cout<<"["<<head->data<<","<<(head->random?head->random->data:-1)<<"] "; head=head->next; } cout<<endl;
}

int main(){
    Node* n1=new Node(1); Node* n2=new Node(2); Node* n3=new Node(3);
    n1->next=n2; n2->next=n3; n1->random=n3; n2->random=n1; n3->random=n2;
    Node* cloned=cloneList(n1);
    printList(cloned);
}
