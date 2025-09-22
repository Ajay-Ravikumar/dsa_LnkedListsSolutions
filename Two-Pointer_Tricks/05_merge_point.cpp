/* 30. Find if two linked lists merge and return merge point */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

int getMergePoint(Node* a,Node* b){
    Node *p=a,*q=b;
    while(p!=q){ p=p?p->next:b; q=q?q->next:a; }
    return p?p->data:-1;
}

int main(){
    Node* common=new Node(99);
    Node* a=new Node(1); a->next=common;
    Node* b=new Node(2); b->next=common;
    cout<<"Merge point: "<<getMergePoint(a,b)<<endl;
}
