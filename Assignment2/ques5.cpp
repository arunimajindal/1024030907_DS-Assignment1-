#include <bits/stdc++.h>
using namespace std;

// (a) Diagonal Matrix
struct Diagonal {
    vector<int> diag;
    Diagonal(int n) { diag.resize(n); }
    void set(int i, int j, int x) { if (i==j) diag[i] = x; }
    int get(int i, int j) { return (i==j) ? diag[i] : 0; }
};

// (b) Tri-diagonal Matrix
struct TriDiagonal {
    vector<int> tri;
    int n;
    TriDiagonal(int n): n(n) { tri.resize(3*n - 2); }
    void set(int i, int j, int x) {
        if (i-j==0) tri[i] = x;               // main diag
        else if (i-j==1) tri[n+i-1] = x;      // lower diag
        else if (j-i==1) tri[2*n-1+i] = x;    // upper diag
    }
    int get(int i, int j) {
        if (i-j==0) return tri[i];
        else if (i-j==1) return tri[n+i-1];
        else if (j-i==1) return tri[2*n-1+i];
        else return 0;
    }
};

// (c) Lower Triangular Matrix
struct LowerTriangular {
    vector<int> lower;
    int n;
    LowerTriangular(int n): n(n) { lower.resize(n*(n+1)/2); }
    void set(int i, int j, int x) {
        if (i>=j) lower[i*(i+1)/2 + j] = x;
    }
    int get(int i, int j) {
        return (i>=j) ? lower[i*(i+1)/2 + j] : 0;
    }
};

// (d) Upper Triangular Matrix
struct UpperTriangular {
    vector<int> upper;
    int n;
    UpperTriangular(int n): n(n) { upper.resize(n*(n+1)/2); }
    void set(int i, int j, int x) {
        if (i<=j) upper[i*n - (i*(i-1))/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        return (i<=j) ? upper[i*n - (i*(i-1))/2 + (j-i)] : 0;
    }
};

// (e) Symmetric Matrix
struct Symmetric {
    vector<int> sym;
    int n;
    Symmetric(int n): n(n) { sym.resize(n*(n+1)/2); }
    void set(int i, int j, int x) {
        if (i>=j) sym[i*(i+1)/2 + j] = x;
        else sym[j*(j+1)/2 + i] = x;
    }
    int get(int i, int j) {
        return (i>=j) ? sym[i*(i+1)/2 + j] : sym[j*(j+1)/2 + i];
    }
};

int main() {
    int n = 4;

    // Diagonal Matrix
    Diagonal D(n);
    D.set(0,0,5); D.set(1,1,8); D.set(2,2,3); D.set(3,3,6);

    cout << "Diagonal Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<D.get(i,j)<<" ";
        cout<<"\n";
    }

    // TriDiagonal Matrix
    TriDiagonal T(n);
    T.set(0,0,1); T.set(0,1,2);
    T.set(1,0,3); T.set(1,1,4); T.set(1,2,5);
    T.set(2,1,6); T.set(2,2,7); T.set(2,3,8);
    T.set(3,2,9); T.set(3,3,10);

    cout << "\nTriDiagonal Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<T.get(i,j)<<" ";
        cout<<"\n";
    }

    // Lower Triangular Matrix
    LowerTriangular L(n);
    int val = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            L.set(i,j,val++);

    cout << "\nLower Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<L.get(i,j)<<" ";
        cout<<"\n";
    }

    // Upper Triangular Matrix
    UpperTriangular U(n);
    val = 1;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            U.set(i,j,val++);

    cout << "\nUpper Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<U.get(i,j)<<" ";
        cout<<"\n";
    }

    // Symmetric Matrix
    Symmetric S(n);
    val = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            S.set(i,j,val++);

    cout << "\nSymmetric Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<S.get(i,j)<<" ";
        cout<<"\n";
    }

    // Binary Search Example
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int key;
    cout << "\nBinary Search Example\nArray: ";
    for (int x : arr) cout << x << " ";
    cout << "\nEnter element to search: ";
    cin >> key;

    int left = 0, right = arr.size() - 1, found = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            found = mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (found != -1)
        cout << "Element found at index " << found << endl;
    else
        cout << "Element not found\n";

    return 0;
}