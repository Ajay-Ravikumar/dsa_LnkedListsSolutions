/* 32. Swap kth node from beginning with kth node from end */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

int length(Node* h){ int c=0; while(h){ c++; h=h->next;} return c; }

void swapKth(Node* head,int k){
    int n=length(head); if(k>n) return;
    Node *x=head; for(int i=1;i<k;i++) x=x->next;
    Node *y=head; for(int i=1;i<n-k+1;i++) y=y->next;
    swap(x->data,y->data);
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4);
    swapKth(h,2); printList(h);
}
