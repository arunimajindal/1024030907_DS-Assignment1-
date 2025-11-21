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
    else if(x>r->data) r->right=insert(r->right,x);
    return r;
}

Node* findMinNode(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* del(Node* r,int x){
    if(!r) return r;
    if(x<r->data) r->left=del(r->left,x);
    else if(x>r->data) r->right=del(r->right,x);
    else{
        if(!r->left) return r->right;
        else if(!r->right) return r->left;
        Node* t=findMinNode(r->right);
        r->data=t->data;
        r->right=del(r->right,t->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    int l=maxDepth(r->left);
    int rr=maxDepth(r->right);
    return 1+max(l,rr);
}

int minDepth(Node* r){
    if(!r) return 0;
    int l=minDepth(r->left);
    int rr=minDepth(r->right);
    return 1+min(l,rr);
}

int main(){
    Node *root=NULL;
    root=insert(root,15);
    insert(root,10);
    insert(root,20);
    insert(root,5);

    cout<<maxDepth(root)<<"\n";
    cout<<minDepth(root)<<"\n";

    root=del(root,10);
}
