#include <iostream>
using namespace std;

int main(){
    int n, e;
    cout<<"Enter vertices: ";
    cin>>n;

    int g[20][20] = {0};

    cout<<"Enter edges: ";
    cin>>e;

    cout<<"Enter edges (u v):\n";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    cout<<"\nAdjacency Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<g[i][j]<<" ";
        cout<<"\n";
    }

    int v;
    cout<<"\nEnter vertex to find degree: ";
    cin>>v;
    int deg = 0;
    for(int i=0;i<n;i++) if(g[v][i]==1) deg++;
    cout<<"Degree = "<<deg<<"\n";

    cout<<"Adjacent vertices: ";
    for(int i=0;i<n;i++)
        if(g[v][i]==1) cout<<i<<" ";

    cout<<"\nNumber of edges = "<<e;
}
