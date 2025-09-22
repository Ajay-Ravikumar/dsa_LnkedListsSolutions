/* 42. Merge K sorted linked lists (LeetCode 23 – using min-heap) */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

struct compare{ bool operator()(Node* a,Node* b){ return a->data>b->data; } };

Node* mergeKLists(vector<Node*>& lists){
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(Node* l: lists) if(l) pq.push(l);
    Node dummy(0); Node* tail=&dummy;
    while(!pq.empty()){
        Node* cur=pq.top(); pq.pop();
        tail->next=cur; tail=tail->next;
        if(cur->next) pq.push(cur->next);
    }
    return dummy.next;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* a=new Node(1); a->next=new Node(4); a->next->next=new Node(5);
    Node* b=new Node(1); b->next=new Node(3); b->next->next=new Node(4);
    Node* c=new Node(2); c->next=new Node(6);
    vector<Node*> lists={a,b,c};
    Node* res=mergeKLists(lists);
    printList(res);
}
