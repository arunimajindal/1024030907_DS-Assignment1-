#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){ data=x; next=NULL; }
};

Node *head=NULL;

void insert(int x){
    Node *t=new Node(x);
    if(!head){ head=t; return; }
    Node *p=head;
    while(p->next) p=p->next;
    p->next=t;
}

bool isCircular(){
    if(!head) return false;
    Node *p=head->next;

    while(p && p!=head){
        p=p->next;
    }
    return (p==head);
}

int main(){
    insert(2);
    insert(4);
    insert(6);
    insert(7);
    insert(5);

    // make it circular
    Node *p=head;
    while(p->next) p=p->next;
    p->next=head;

    cout<<(isCircular()?"True":"False");
}
