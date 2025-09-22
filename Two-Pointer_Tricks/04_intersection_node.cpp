/* 29. Find intersection node of two linked lists (LeetCode 160) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

int getLength(Node* head){ int len=0; while(head){ len++; head=head->next;} return len; }

Node* getIntersection(Node* a,Node* b){
    int lenA=getLength(a), lenB=getLength(b);
    while(lenA>lenB){ a=a->next; lenA--; }
    while(lenB>lenA){ b=b->next; lenB--; }
    while(a && b){ if(a==b) return a; a=a->next; b=b->next; }
    return nullptr;
}

int main(){
    Node* common=new Node(8);
    Node* a=new Node(1); a->next=common;
    Node* b=new Node(2); b->next=common;
    Node* res=getIntersection(a,b);
    if(res) cout<<"Intersection at "<<res->data<<endl;
    else cout<<"No intersection\n";
}
