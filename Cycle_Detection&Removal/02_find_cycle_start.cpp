/* 22. Find the node where the cycle begins (LeetCode 142: Linked List Cycle II) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* detectCycle(Node* head){
    Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){ slow=slow->next; fast=fast->next; }
            return slow;
        }
    }
    return nullptr;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=head->next;
    Node* start=detectCycle(head);
    if(start) cout<<"Cycle starts at: "<<start->data<<endl;
    else cout<<"No cycle"<<endl;
}
