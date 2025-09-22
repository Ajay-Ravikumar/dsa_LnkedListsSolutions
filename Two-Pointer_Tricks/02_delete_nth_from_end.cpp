/* 27. Delete nth node from the end (LeetCode 19) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* deleteNthFromEnd(Node* head,int n){
    Node dummy(0); dummy.next=head; Node *first=&dummy,*second=&dummy;
    for(int i=0;i<=n;i++) first=first->next;
    while(first){ first=first->next; second=second->next; }
    Node* del=second->next; second->next=del->next; delete del;
    return dummy.next;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4);
    head=deleteNthFromEnd(head,2);
    printList(head);
}
