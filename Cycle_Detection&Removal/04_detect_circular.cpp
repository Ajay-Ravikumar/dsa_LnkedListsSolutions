/* 24. Detect if a circular linked list is circular from start */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

bool isCircular(Node* head){
    if(!head) return false;
    Node* temp=head->next;
    while(temp && temp!=head) temp=temp->next;
    return temp==head;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=head;
    cout<<"Is circular? "<<(isCircular(head)?"Yes":"No")<<endl;
}
