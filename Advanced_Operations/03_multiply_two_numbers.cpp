/* 38. Multiply two numbers represented by linked lists */

#include <iostream>
#include <vector>
using namespace std;

struct Node{ int data; Node* next; Node(int d):data(d),next(nullptr){} };

Node* multiplyTwoNumbers(Node* l1, Node* l2){
    vector<int> num1,num2;
    while(l1){ num1.push_back(l1->data); l1=l1->next; }
    while(l2){ num2.push_back(l2->data); l2=l2->next; }
    vector<int> result(num1.size()+num2.size(),0);
    for(int i=0;i<num1.size();i++){
        for(int j=0;j<num2.size();j++){
            result[i+j]+=num1[i]*num2[j];
        }
    }
    int carry=0;
    for(int i=0;i<result.size();i++){ int sum=result[i]+carry; result[i]=sum%10; carry=sum/10; }
    Node* head=nullptr; Node* tail=nullptr;
    for(int v: result){
        Node* n=new Node(v);
        if(!head){ head=tail=n; } else { tail->next=n; tail=n; }
    }
    while(head && head->next && head->data==0){ Node* tmp=head; head=head->next; delete tmp; }
    return head;
}

void printList(Node* h){ while(h){ cout<<h->data<<" "; h=h->next;} cout<<endl; }

int main(){
    Node* a=new Node(3); a->next=new Node(4); a->next->next=new Node(2); // 243
    Node* b=new Node(4); b->next=new Node(6); b->next->next=new Node(5); // 564
    Node* res=multiplyTwoNumbers(a,b);
    printList(res); // Expected 2->0->7->1->3 (137052)
}
