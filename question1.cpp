/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void createArray(int arr[], int &n)
{
    
    cout<<"Enter number of elements in array: "<<endl;
    cin>>n;
    //int arr[];
    
    cout<<"enter elements in array:"<<endl;
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
}

void displayArray(int arr[], int &n)
{
    cout<<"Entered array is: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertElement(int arr[], int &n)
{
    int element,position;
    cout<<"Enter the position where you want to add the element:"<<endl;
    cin>>position;
    
    cout<<"Enter the element you want to add:"<<endl;
    cin>>element;
    
    if(position>n)
    {
        cout<<"Invalid"<<endl;
    }
    for(int i = n-1; i >= position-1; i--)
    {
        arr[i] = arr[i-1];
    }
    n++;
    arr[position - 1] = element;
}

void deleteElement(int arr[], int &n)
{
    int position, element;
    cout<<"Enter the position of the element you want to delete:"<<endl;
    cin>>position;
    
    if(position<1 || position>n)
    {
        cout<<"Invalid"<<endl;
        return;
    }
    for(int i = position-1; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
    return;
}

void linearSearch(int arr[], int n)
{
    int element;
    int position;
    int found = 0;
    cout<<"Enter the element you want to search:"<<endl;
    cin>>element;
    
    for(int i = 0; i<=n; i++)
    {
        if(arr[i] == element)
        {
            position = i+1;
            found = 1;
        }
    }
    
    if(found == 0 )
    {
        cout<<"Error 404 - Element not found"<<endl;
    }
    if(found == 1)
    {
        cout<<"Element found at position: "<<position<<endl;
    }
}

int main()
{

    int arr[100];
    int n = 0;
    int arrCreated = 0;
    int count;
    
    int selectOp;
    while(selectOp != 6)
    {
    cout<<endl;
    cout<<"Choose:"<<endl;
    cout<<"Create array --> 1"<<endl<<"Display Array --> 2"<<endl;
    cout<<"Insert Element --> 3"<<endl<<"Delete Element --> 4"<<endl;;
    cout<<"Search Element --> 5"<<endl;
    cout<<"Exit --> 6"<<endl;
    cin>>selectOp;
    
    
    switch(selectOp)
    {
        case 1: 
        if(arrCreated == 0)
        {
            createArray(arr,n);
            arrCreated = 1;
        }
    
        else
        {
            cout<<"Array already created"<<endl;
            for(int i = 0; i<n; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        break;
        
        case 2: 
        if(arrCreated == 0) cout<<"Please Create an Array."<<endl;
        if(arrCreated == 1)
        {
            displayArray(arr,n);
        }
        break;
        
        case 3:
        if(arrCreated == 0) cout<<"Array not created."<<endl;
        if(arrCreated == 1)
        {
            if(count == n)
            {
                cout<<"No space in array."<<endl;
                cout<<"try deleting an element first"<<endl;
            }
            else
            {
                insertElement(arr, n);
            }
        }
        break;
        
        case 4:
        if(arrCreated == 0) cout<<"Array not created."<<endl;
        if(arrCreated == 1)
        {
            deleteElement(arr,n);
        }
        break;
        
        case 5:
        if(arrCreated == 0) cout<<"Array not created."<<endl;
        
        if(arrCreated == 1)
        {
            linearSearch(arr, n);
        }
        break;
    }
    }

    return 0;
}