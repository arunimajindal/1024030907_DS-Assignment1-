#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i){
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapifyMax(a,n,largest);
    }
}

void heapifyMin(int a[], int n, int i){
    int smallest=i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]<a[smallest]) smallest=l;
    if(r<n && a[r]<a[smallest]) smallest=r;
    if(smallest!=i){
        swap(a[i],a[smallest]);
        heapifyMin(a,n,smallest);
    }
}

void heapSortIncreasing(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyMax(a,n,i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapifyMax(a,i,0);
    }
}

void heapSortDecreasing(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyMin(a,n,i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapifyMin(a,i,0);
    }
}

int main(){
    int a[20], n, ch;
    cout<<"Size: "; cin>>n;
    cout<<"Elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<"1. Increasing Order\n2. Decreasing Order\n";
    cin>>ch;

    if(ch==1) heapSortIncreasing(a,n);
    else heapSortDecreasing(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
