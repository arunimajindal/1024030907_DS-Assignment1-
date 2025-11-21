#include <iostream>
using namespace std;

int main(){
    int n, start;
    cout<<"Vertices: ";
    cin>>n;

    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    cout<<"Start: ";
    cin>>start;

    int dist[20], vis[20]={0};

    for(int i=0;i<n;i++){
        dist[i]=9999;
    }
    dist[start]=0;

    for(int k=0;k<n;k++){
        int min=9999, u;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<min){
                min=dist[i];
                u=i;
            }

        vis[u]=1;

        for(int v=0;v<n;v++){
            if(g[u][v] && dist[u]+g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
        }
    }

    for(int i=0;i<n;i++)
        cout<<"Distance to "<<i<<" = "<<dist[i]<<"\n";
}
