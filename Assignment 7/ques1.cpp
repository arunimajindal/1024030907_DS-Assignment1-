#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[50], R[50];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[], int l, int r){
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=partition(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

void print(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int a[50], n, choice;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<"1.Selection\n2.Insertion\n3.Bubble\n4.Merge\n5.Quick\n";
    cin>>choice;

    if(choice==1) selectionSort(a,n);
    else if(choice==2) insertionSort(a,n);
    else if(choice==3) bubbleSort(a,n);
    else if(choice==4) mergeSort(a,0,n-1);
    else if(choice==5) quickSort(a,0,n-1);

    cout<<"Sorted: ";
    print(a,n);
}
