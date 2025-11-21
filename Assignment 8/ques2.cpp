#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

Node* insert(Node* r,int x){
    if(!r) return new Node(x);
    if(x<r->data) r->left=insert(r->left,x);
    else r->right=insert(r->right,x);
    return r;
}

bool searchRec(Node* r,int x){
    if(!r) return false;
    if(r->data==x) return true;
    if(x<r->data) return searchRec(r->left,x);
    return searchRec(r->right,x);
}

bool searchNon(Node* r,int x){
    while(r){
        if(r->data==x) return true;
        if(x<r->data) r=r->left;
        else r=r->right;
    }
    return false;
}

int findMin(Node* r){
    while(r->left) r=r->left;
    return r->data;
}

int findMax(Node* r){
    while(r->right) r=r->right;
    return r->data;
}

Node* successor(Node* r,int x){
    Node *succ=NULL;
    while(r){
        if(x<r->data){ succ=r; r=r->left; }
        else r=r->right;
    }
    return succ;
}

Node* predecessor(Node* r,int x){
    Node *pred=NULL;
    while(r){
        if(x>r->data){ pred=r; r=r->right; }
        else r=r->left;
    }
    return pred;
}

int main(){
    Node *root=NULL;
    root=insert(root,20);
    insert(root,10);
    insert(root,30);

    cout<<searchRec(root,10)<<"\n";
    cout<<findMin(root)<<"\n";
    cout<<findMax(root)<<"\n";
}
