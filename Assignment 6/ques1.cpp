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

DLL *dh = NULL;
CLL *ch = NULL;

// doubly linked list

void dllInsertFirst(int x){
    DLL *t=new DLL(x);
    if(!dh){ dh=t; return; }
    t->next=dh;
    dh->prev=t;
    dh=t;
}

void dllInsertLast(int x){
    DLL *t=new DLL(x);
    if(!dh){ dh=t; return; }
    DLL *p=dh;
    while(p->next) p=p->next;
    p->next=t;
    t->prev=p;
}

void dllInsertAfter(int val,int x){
    DLL *p=dh;
    while(p && p->data!=val) p=p->next;
    if(!p) return;
    DLL *t=new DLL(x);
    t->next=p->next;
    t->prev=p;
    if(p->next) p->next->prev=t;
    p->next=t;
}

void dllInsertBefore(int val,int x){
    if(!dh) return;
    if(dh->data==val){ dllInsertFirst(x); return; }
    DLL *p=dh;
    while(p && p->data!=val) p=p->next;
    if(!p) return;
    DLL *t=new DLL(x);
    t->next=p;
    t->prev=p->prev;
    p->prev->next=t;
    p->prev=t;
}

void dllDelete(int val){
    if(!dh) return;
    DLL *p=dh;

    if(p->data==val){
        dh=p->next;
        if(dh) dh->prev=NULL;
        delete p; return;
    }
    while(p && p->data!=val) p=p->next;
    if(!p) return;

    if(p->next) p->next->prev=p->prev;
    p->prev->next=p->next;
    delete p;
}

bool dllSearch(int val){
    DLL *p=dh;
    while(p){ if(p->data==val) return true; p=p->next; }
    return false;
}

void dllDisplay(){
    DLL *p=dh;
    while(p){ cout<<p->data<<" "; p=p->next; }
    cout<<"\n";
}

// circular linked list

void cllInsertFirst(int x){
    CLL *t=new CLL(x);
    if(!ch){ ch=t; t->next=t; return; }
    CLL *p=ch;
    while(p->next!=ch) p=p->next;
    t->next=ch;
    p->next=t;
    ch=t;
}

void cllInsertLast(int x){
    CLL *t=new CLL(x);
    if(!ch){ ch=t; t->next=t; return; }
    CLL *p=ch;
    while(p->next!=ch) p=p->next;
    p->next=t;
    t->next=ch;
}

void cllInsertAfter(int val,int x){
    if(!ch) return;
    CLL *p=ch;
    do{
        if(p->data==val){
            CLL *t=new CLL(x);
            t->next=p->next;
            p->next=t;
            return;
        }
        p=p->next;
    }while(p!=ch);
}

void cllInsertBefore(int val,int x){
    if(!ch) return;
    CLL *p=ch,*pr=NULL;
    do{
        if(p->data==val){
            if(p==ch){ cllInsertFirst(x); return; }
            CLL *t=new CLL(x);
            t->next=p;
            pr->next=t;
            return;
        }
        pr=p; p=p->next;
    }while(p!=ch);
}

void cllDelete(int val){
    if(!ch) return;
    CLL *p=ch,*pr=NULL;

    do{
        if(p->data==val){
            if(p==ch){
                CLL *end=ch;
                while(end->next!=ch) end=end->next;
                if(end==ch){ delete ch; ch=NULL; return; }
                end->next=ch->next;
                ch=ch->next;
                delete p; return;
            }
            pr->next=p->next;
            delete p; return;
        }
        pr=p; p=p->next;
    }while(p!=ch);
}

bool cllSearch(int val){
    if(!ch) return false;
    CLL *p=ch;
    do{
        if(p->data==val) return true;
        p=p->next;
    }while(p!=ch);
    return false;
}

void cllDisplay(){
    if(!ch){ cout<<"\n"; return; }
    CLL *p=ch;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=ch);
    cout<<"\n";
}

int main(){
    int ch1,ch2,x,val;

    while(true){
        cout<<"\n1 DLL Operations\n2 CLL Operations\n3 Exit\n";
        cin>>ch1;

        if(ch1==1){
            cout<<"1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n5 Delete\n6 Search\n7 Display\n";
            cin>>ch2;

            if(ch2==1){ cin>>x; dllInsertFirst(x); }
            else if(ch2==2){ cin>>x; dllInsertLast(x); }
            else if(ch2==3){ cin>>val>>x; dllInsertAfter(val,x); }
            else if(ch2==4){ cin>>val>>x; dllInsertBefore(val,x); }
            else if(ch2==5){ cin>>val; dllDelete(val); }
            else if(ch2==6){ cin>>val; cout<<(dllSearch(val)?"Found\n":"Not Found\n"); }
            else if(ch2==7){ dllDisplay(); }
        }

        else if(ch1==2){
            cout<<"1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n5 Delete\n6 Search\n7 Display\n";
            cin>>ch2;

            if(ch2==1){ cin>>x; cllInsertFirst(x); }
            else if(ch2==2){ cin>>x; cllInsertLast(x); }
            else if(ch2==3){ cin>>val>>x; cllInsertAfter(val,x); }
            else if(ch2==4){ cin>>val>>x; cllInsertBefore(val,x); }
            else if(ch2==5){ cin>>val; cllDelete(val); }
            else if(ch2==6){ cin>>val; cout<<(cllSearch(val)?"Found\n":"Not Found\n"); }
            else if(ch2==7){ cllDisplay(); }
        }

        else if(ch1==3) break;
    }
}
