/* 19. Reverse a circular linked list */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverseCircular(Node* head){
    if(!head || head->next==head) return head;
    Node *prev=nullptr,*curr=head,*next=nullptr;
    do{
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    } while(curr!=head);
    head->next=prev;
    return prev;
}

void printCirc(Node* head){
    if(!head) return;
    Node* temp=head;
    do{ cout<<temp->data<<"->"; temp=temp->next; }while(temp!=head);
    cout<<"(back to head)\n";
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=head;
    cout<<"Original: "; printCirc(head);
    head=reverseCircular(head);
    cout<<"Reversed circular: "; printCirc(head);
}
