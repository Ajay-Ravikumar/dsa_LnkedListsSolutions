/* 20. Check if a linked list is palindrome (reverse second half + compare) */

#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}};

Node* reverse(Node* head){ Node* prev=nullptr,*curr=head,*next; while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; } return prev; }

bool isPalindrome(Node* head){
    if(!head||!head->next) return true;
    Node* slow=head,*fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    Node* second=reverse(slow->next);
    Node* copy=second;
    Node* first=head;
    while(second){ if(first->data!=second->data) return false; first=first->next; second=second->next; }
    reverse(copy);
    return true;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(2); head->next->next->next=new Node(1);
    cout<<"Palindrome? "<<(isPalindrome(head)?"Yes":"No")<<endl;
}
