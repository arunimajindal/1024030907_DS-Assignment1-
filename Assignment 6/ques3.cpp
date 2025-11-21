#include <iostream>
using namespace std;

struct DLL {
    int data;
    DLL *prev, *next;
    DLL(int x){ data=x; prev=next=NULL; }
};

struct CLL {
    int data;
    CLL *next;
    CLL(int x){ data=x; next=NULL; }
};

DLL *dh=NULL;
CLL *ch=NULL;

void dllInsert(int x){
    DLL *t=new DLL(x);
    if(!dh){ dh=t; return; }
    DLL *p=dh;
    while(p->next) p=p->next;
    p->next=t; t->prev=p;
}

void cllInsert(int x){
    CLL *t=new CLL(x);
    if(!ch){ ch=t; t->next=t; return; }
    CLL *p=ch;
    while(p->next!=ch) p=p->next;
    p->next=t; t->next=ch;
}

int dllSize(){
    int c=0; DLL *p=dh;
    while(p){ c++; p=p->next; }
    return c;
}

int cllSize(){
    if(!ch) return 0;
    int c=0; CLL *p=ch;
    do{ c++; p=p->next; } while(p!=ch);
    return c;
}

int main(){
    dllInsert(10);
    dllInsert(20);
    dllInsert(30);

    cllInsert(40);
    cllInsert(50);
    cllInsert(60);

    cout<<"DLL Size = "<<dllSize()<<endl;
    cout<<"CLL Size = "<<cllSize()<<endl;
}
