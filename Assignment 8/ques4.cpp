#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

bool isBST(Node* r,int mn,int mx){
    if(!r) return true;
    if(r->data<=mn || r->data>=mx) return false;
    return isBST(r->left,mn,r->data) &&
           isBST(r->right,r->data,mx);
}

int main(){
    Node* root=new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);

    cout<<(isBST(root,-99999,99999)?"YES":"NO");
}
