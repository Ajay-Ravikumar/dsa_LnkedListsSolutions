/* 18. Reverse the entire list except for last k nodes */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverseExceptLastK(Node* head,int k){
    int len=0; Node* temp=head;
    while(temp){ len++; temp=temp->next; }
    int n=len-k; if(n<=0) return head;
    Node *prev=nullptr,*curr=head,*next=nullptr; int count=0;
    while(curr && count<n){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
    head->next=curr;
    return prev;
}

void printList(Node* h){ while(h){ cout<<h->data<<"->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5);
    cout<<"Original: "; printList(head);
    head=reverseExceptLastK(head,2);
    cout<<"Reversed except last 2: "; printList(head);
}
