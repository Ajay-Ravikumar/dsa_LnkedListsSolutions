/* 23. Remove cycle in a linked list */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

void removeCycle(Node* head){
    Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) break;
    }
    if(!fast || !fast->next) return;
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next; fast=fast->next;
    }
    fast->next=nullptr;
}

bool hasCycle(Node* head){
    Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=head;
    cout<<"Before removal: "<<(hasCycle(head)?"Has cycle":"No cycle")<<endl;
    removeCycle(head);
    cout<<"After removal: "<<(hasCycle(head)?"Has cycle":"No cycle")<<endl;
}
