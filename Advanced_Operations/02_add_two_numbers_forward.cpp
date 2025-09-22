/* 37. Add two numbers (digits stored in forward order – LeetCode 445) */

#include <iostream>
#include <stack>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* addTwoNumbers(Node* l1, Node* l2){
    stack<int> s1,s2;
    while(l1){ s1.push(l1->data); l1=l1->next; }
    while(l2){ s2.push(l2->data); l2=l2->next; }
    Node* head=nullptr;
    int carry=0;
    while(!s1.empty() || !s2.empty() || carry){
        int sum=carry;
        if(!s1.empty()){ sum+=s1.top(); s1.pop(); }
        if(!s2.empty()){ sum+=s2.top(); s2.pop(); }
        Node* n=new Node(sum%10);
        n->next=head; head=n;
        carry=sum/10;
    }
    return head;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }

int main(){
    Node* a=new Node(7); a->next=new Node(2); a->next->next=new Node(4); a->next->next->next=new Node(3);
    Node* b=new Node(5); b->next=new Node(6); b->next->next=new Node(4);
    Node* res=addTwoNumbers(a,b);
    printList(res);
}
