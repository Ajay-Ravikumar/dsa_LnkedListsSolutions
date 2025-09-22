/* 16. Reverse a doubly linked list */

#include <iostream>
using namespace std;

struct DNode{
    int data; DNode* prev; DNode* next;
    DNode(int d):data(d),prev(nullptr),next(nullptr){}
};

DNode* reverseDLL(DNode* head){
    DNode* temp=nullptr; DNode* curr=head;
    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp) head=temp->prev;
    return head;
}

void printList(DNode* h){ while(h){ cout<<h->data<<"<->"; h=h->next;} cout<<"NULL\n"; }

int main(){
    DNode* head=new DNode(1); head->next=new DNode(2); head->next->prev=head; head->next->next=new DNode(3); head->next->next->prev=head->next;
    cout<<"Original: "; printList(head);
    head=reverseDLL(head);
    cout<<"Reversed: "; printList(head);
}
