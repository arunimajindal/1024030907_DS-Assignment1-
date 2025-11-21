#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Vertices: ";
    cin>>n;

    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    int vis[20]={0};
    vis[0]=1;

    cout<<"Prim MST:\n";

    for(int k=0;k<n-1;k++){
        int min=9999,u=0,v=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                for(int j=0;j<n;j++){
                    if(!vis[j] && g[i][j] && g[i][j]<min){
                        min=g[i][j];
                        u=i; v=j;
                    }
                }
            }
        }
        vis[v]=1;
        cout<<u<<" - "<<v<<" = "<<min<<"\n";
    }
}
