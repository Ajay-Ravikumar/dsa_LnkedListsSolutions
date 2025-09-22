/* 36. Add two numbers represented by linked lists (LeetCode 2) */

#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* addTwoNumbers(Node* l1, Node* l2){
    Node dummy(0); Node* curr=&dummy;
    int carry=0;
    while(l1 || l2 || carry){
        int sum = carry + (l1?l1->data:0) + (l2?l2->data:0);
        carry = sum/10;
        curr->next = new Node(sum%10);
        curr=curr->next;
        if(l1) l1=l1->next; if(l2) l2=l2->next;
    }
    return dummy.next;
}

void printList(Node* head){ while(head){ cout<<head->data<<" "; head=head->next; } cout<<endl; }

int main(){
    Node* a=new Node(2); a->next=new Node(4); a->next->next=new Node(3);
    Node* b=new Node(5); b->next=new Node(6); b->next->next=new Node(4);
    Node* res=addTwoNumbers(a,b);
    printList(res);
}
