/* 21. Detect if a cycle exists (Floyd’s Cycle Detection – tortoise and hare) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

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
    cout<<"Has cycle? "<<(hasCycle(head)?"Yes":"No")<<endl;
}
