/* 50. Check if a doubly linked list is palindrome */

#include <iostream>
using namespace std;

struct Node{
    int data; Node* next; Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* start=head; Node* end=head;
    while(end->next) end=end->next;
    while(start!=end && end->next!=start){
        if(start->data!=end->data) return false;
        start=start->next; end=end->prev;
    }
    return true;
}

int main(){
    Node* head=new Node(1); head->next=new Node(2); head->next->prev=head;
    head->next->next=new Node(2); head->next->next->prev=head->next;
    head->next->next->next=new Node(1); head->next->next->next->prev=head->next->next;
    cout<<"Is palindrome? "<<(isPalindrome(head)?"Yes":"No")<<endl;
}
