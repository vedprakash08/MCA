#include<iostream>
using namespace std;

/* B. Write code in C++ to sort an array of integers in ascending order. */

//----------->>> Using Quick Sort to sort an array 
// Partition function 
int partition(int arr[], int s, int e){
    int pivot= arr[s];
    int count=0;
    
    // find number of element in array which are smaller than pivot
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    // pivot index
    int pivotIndex= s+count;
    swap(arr[pivotIndex], arr[s]);

    // now arrange all the element in an array in such a manner that all the elements smaller then pivot are on left side of pivot 
    //while bigger are on the right side of the pivot

    int i=s; int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=arr[pivotIndex]){
            i++;
        }

        while(arr[j]>arr[pivotIndex]){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}


// quick sort 
void quickSort(int arr[], int s, int e){
    // base case
    if(s>=e)
    return;
    
    int p= partition( arr, s,  e);

    // left part sort karo
    quickSort(arr, s, p-1);

    // right part sort karo
    quickSort(arr, p+1, e);

}
int main()
{
    int arr[]={3,7,2,2,10,54,8};
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);

    cout<<"Sorted array is "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}