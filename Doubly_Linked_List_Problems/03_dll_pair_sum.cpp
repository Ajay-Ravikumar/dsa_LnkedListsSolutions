/* 48. Find pairs with given sum in a sorted doubly linked list */

#include <iostream>
using namespace std;

struct Node{
    int data; Node* next; Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};

void findPairs(Node* head,int sum){
    Node* start=head; Node* end=head;
    while(end->next) end=end->next;
    while(start && end && start!=end && end->next!=start){
        int s=start->data+end->data;
        if(s==sum){ cout<<"("<<start->data<<","<<end->data<<") "; start=start->next; end=end->prev; }
        else if(s<sum) start=start->next;
        else end=end->prev;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->prev=head;
    head->next->next=new Node(4); head->next->next->prev=head->next;
    head->next->next->next=new Node(5); head->next->next->next->prev=head->next->next;
    findPairs(head,6); // Expected (1,5),(2,4)
}
