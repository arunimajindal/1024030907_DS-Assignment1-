#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

void preorder(Node *r){
    if(!r) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r){
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node *r){
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right= new Node(20);

    preorder(root); cout<<"\n";
    inorder(root); cout<<"\n";
    postorder(root);
}
