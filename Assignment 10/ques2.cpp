#include <iostream>
using namespace std;

int g[20][20], n;
int q[20], front=0, rear=0;
int vis[20]={0};

void bfs(int s){
    vis[s]=1;
    q[rear++] = s;

    while(front < rear){
        int u = q[front++];
        cout<<u<<" ";

        for(int v=0; v<n; v++){
            if(g[u][v]==1 && !vis[v]){
                vis[v]=1;
                q[rear++] = v;
            }
        }
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

    cout<<"Start vertex: ";
    cin>>start;

    bfs(start);
}
