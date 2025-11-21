#include <iostream>
using namespace std;

int g[20][20], n;
int vis2[20]={0};

void dfs(int u){
    vis2[u]=1;
    cout<<u<<" ";

    for(int v=0; v<n; v++){
        if(g[u][v]==1 && !vis2[v])
            dfs(v);
    }
}

int main(){
    int e,u,v,start;
    cout<<"Vertices: "; cin>>n;
    cout<<"Edges: "; cin>>e;

    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }

    cout<<"Start: "; cin>>start;
    dfs(start);
}
