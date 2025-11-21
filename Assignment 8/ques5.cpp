#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

void inorder(Node* r){
    stack<Node*> s;
    Node* cur=r;

    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top(); s.pop();
        cout<<cur->data<<" ";
        cur=cur->right;
    }
}

int main(){
    Node* r=new Node(10);
    r->left=new Node(5);
    r->right=new Node(15);

    inorder(r);
}
