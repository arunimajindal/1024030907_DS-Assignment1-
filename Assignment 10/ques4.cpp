#include <iostream>
using namespace std;

struct Edge{
    int u,v,w;
};

int find(int parent[], int x){
    while(parent[x] != x) x = parent[x];
    return x;
}

void uni(int parent[], int x, int y){
    parent[x] = y;
}

int main(){
    int n,e;
    cout<<"Vertices: "; cin>>n;
    cout<<"Edges: "; cin>>e;

    Edge edges[50];
    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;

    for(int i=0;i<e;i++)
        for(int j=i+1;j<e;j++)
            if(edges[j].w < edges[i].w)
                swap(edges[i],edges[j]);

    int parent[20];
    for(int i=0;i<n;i++) parent[i]=i;

    cout<<"Kruskal MST:\n";
    for(int i=0;i<e;i++){
        int x=find(parent, edges[i].u);
        int y=find(parent, edges[i].v);
        if(x!=y){
            cout<<edges[i].u<<" - "<<edges[i].v<<" = "<<edges[i].w<<"\n";
            uni(parent,x,y);
        }
    }
}
