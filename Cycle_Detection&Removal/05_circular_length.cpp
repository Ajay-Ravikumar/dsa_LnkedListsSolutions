/* 25. Length of cycle in a linked list */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

int cycleLength(Node* head){
    Node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast){
            int len=1; fast=fast->next;
            while(slow!=fast){ len++; fast=fast->next; }
            return len;
        }
    }
    return 0;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=head->next;
    cout<<"Cycle length: "<<cycleLength(head)<<endl;
}
