/* 17. Reverse only the sublist between positions m and n (LeetCode 92: Reverse Linked List II) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverseBetween(Node* head,int m,int n){
    if(!head) return nullptr;
    Node dummy(0); dummy.next=head; Node* prev=&dummy;
    for(int i=1;i<m;i++) prev=prev->next;
    Node* curr=prev->next;
    for(int i=0;i<n-m;i++){
        Node* temp=curr->next;
        curr->next=temp->next;
        temp->next=prev->next;
        prev->next=temp;
    }
    return dummy.next;
}

void printList(Node* h){ while(h){ cout<<h->data<<"->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5);
    cout<<"Original: "; printList(head);
    head=reverseBetween(head,2,4);
    cout<<"Reverse 2-4: "; printList(head);
}
