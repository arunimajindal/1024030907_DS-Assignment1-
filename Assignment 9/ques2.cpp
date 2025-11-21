#include <iostream>
using namespace std;

int heapArr[50], heapSize=0;

void insertPQ(int x){
    int i = heapSize;
    heapArr[heapSize++] = x;

    while(i>0){
        int p = (i-1)/2;
        if(heapArr[p] < heapArr[i]) swap(heapArr[p],heapArr[i]);
        i = p;
    }
}

int deletePQ(){
    if(heapSize==0) return -1;

    int root = heapArr[0];
    heapArr[0] = heapArr[--heapSize];

    int i=0;
    while(true){
        int l=2*i+1, r=2*i+2, largest=i;

        if(l<heapSize && heapArr[l]>heapArr[largest]) largest=l;
        if(r<heapSize && heapArr[r]>heapArr[largest]) largest=r;

        if(largest==i) break;
        swap(heapArr[i],heapArr[largest]);
        i=largest;
    }
    return root;
}

void displayPQ(){
    for(int i=0;i<heapSize;i++) cout<<heapArr[i]<<" ";
    cout<<"\n";
}

int main(){
    insertPQ(40);
    insertPQ(10);
    insertPQ(50);
    insertPQ(30);

    displayPQ();

    cout<<"Deleted: "<<deletePQ()<<"\n";
    displayPQ();
}
