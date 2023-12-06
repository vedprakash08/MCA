#include<iostream>
using namespace std;
//C. write C++ program to find the union of two arrays, returning all unique elements. 


// Quick sort for sorting an array

//----------->>> Using Quick Sort to sort an array to find the intersection
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
    int arr1[6]={2,5,2,8,4,5};
    int n1=sizeof(arr1)/sizeof(int);;
    int arr2[5]={3,4,2,5,1};
    int n2=sizeof(arr2)/sizeof(int);;
    quickSort(arr1,0,5);
    quickSort(arr2,0,4);

    // Using two pointer approach 
    int i=0, j=0;
    cout<< "Union of two arrays is "<<endl;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i++]<<" ";
        }

        if(arr1[i]>arr2[j]){
            cout<<arr2[j++]<<" ";
        }
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++; j++;
        }

    }
    // Remaining element of  the arr1 
    while(i<n1)
    cout<<arr1[i++]<<" ";

    //Remaining element of  the arr2 
    while(j<n2)
    cout<<arr2[j++]<<" ";
    
    return 0;
}