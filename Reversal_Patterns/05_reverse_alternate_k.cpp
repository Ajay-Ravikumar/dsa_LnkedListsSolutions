/* 15. Reverse alternate k nodes in a linked list */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverseAltK(Node* head,int k,bool rev){
    if(!head) return nullptr;
    Node *curr=head,*prev=nullptr,*next=nullptr; int count=0;
    if(rev){
        while(curr && count<k){ next=curr->next; curr->next=prev; prev=curr; curr=next; count++; }
        head->next = reverseAltK(curr,k,!rev);
        return prev;
    } else {
        while(curr && count<k-1){ curr=curr->next; count++; }
        if(curr) curr->next = reverseAltK(curr->next,k,!rev);
        return head;
    }
}

void printList(Node* h){ while(h){ cout<<h->data<<"->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5);
    cout<<"Original: "; printList(head);
    head=reverseAltK(head,2,true);
    cout<<"Reversed alternate k=2: "; printList(head);
}
