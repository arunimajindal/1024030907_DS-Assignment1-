#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
    Node(char x){ data=x; prev=next=NULL; }
};

Node *head=NULL;

void insert(char x){
    Node *t=new Node(x);
    if(!head){ head=t; return; }
    Node *p=head;
    while(p->next) p=p->next;
    p->next=t; t->prev=p;
}

bool isPalindrome(){
    if(!head || !head->next) return true;

    Node *l=head, *r=head;
    while(r->next) r=r->next;

    while(l!=r && r->next!=l){
        if(l->data!=r->data) return false;
        l=l->next;
        r=r->prev;
    }
    return true;
}

int main(){
    insert('r');
    insert('a');
    insert('d');
    insert('a');
    insert('r');

    cout<<(isPalindrome()?"True":"False");
}
