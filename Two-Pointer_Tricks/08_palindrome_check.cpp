/* 33. Check if linked list is palindrome (two-pointer method) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverse(Node* h){
    Node* prev=nullptr,*cur=h;
    while(cur){ Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

bool isPalindrome(Node* head){
    if(!head||!head->next) return true;
    Node *slow=head,*fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    Node* second=reverse(slow->next);
    Node *p1=head,*p2=second;
    while(p2){ if(p1->data!=p2->data) return false; p1=p1->next; p2=p2->next; }
    return true;
}

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(2); h->next->next->next=new Node(1);
    cout<<"Is palindrome? "<<(isPalindrome(h)?"Yes":"No")<<endl;
}
