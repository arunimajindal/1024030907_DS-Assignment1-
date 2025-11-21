#include <iostream>
using namespace std;

struct CLL {
    int data;
    CLL *next;
    CLL(int x){ data=x; next=NULL; }
};

CLL *head = NULL;

void insertLast(int x){
    CLL *t=new CLL(x);
    if(!head){
        head=t; t->next=t;
        return;
    }
    CLL *p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
}

void displayCircular(){
    if(!head){ cout<<"\n"; return; }
    CLL *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<head->data<<" ";  // repeating head
    cout<<"\n";
}

int main(){
    insertLast(20);
    insertLast(100);
    insertLast(40);
    insertLast(80);
    insertLast(60);

    displayCircular();
}
