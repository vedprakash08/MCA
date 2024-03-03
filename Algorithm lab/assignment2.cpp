#include<iostream>
using namespace std;
class sort{
    public:
    /***************Quick Sort*************************/
    int partitionIndex(int start,int end,int*arr){
        int size=sizeof(arr)/sizeof(arr[0]);
        int pivot=arr[start];
        int i=start, j=end;
        while(i<=j){
            while(i<=j && arr[i]<=pivot) i++;
            while(i<=j && arr[j]>pivot) j--;
            if(i<j)
            swap(arr[i++],arr[j--]);
        }
        swap(arr[start],arr[j]);
        return j;
    }

    void quickSort(int*arr,int s,int e){
        if(s>=e) return;

        int partitionIdx=partitionIndex(s,e,arr);
        // left side array
        quickSort(arr,s,partitionIdx-1);
        //right side array
        quickSort(arr,partitionIdx+1,e);
    }
    /***************Merge Sort*************************/

    void mergeArray(int *arr,int s,int e,int mid){
        //length of two arrays
        int len1=mid-s+1;
        int len2=e-mid;
        int *arr1=new int[len1];
        int *arr2=new int[len2];
        int startIndex=s;
        // creating array 1
        for(int i=0; i<len1; i++){
            arr1[i]=arr[startIndex++];
        }
        
        // creating array 2
        for(int i=0; i<len2; i++){
            arr2[i]=arr[startIndex++];
        }

        //merging
        startIndex=s;
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(arr1[i]<=arr2[j]){
                arr[startIndex++]=arr1[i++];
            }
            else{
                arr[startIndex++]=arr2[j++];
            }
        }

        while(i<len1){
            arr[startIndex++]=arr1[i++];
        }
        while(j<len2){
            arr[startIndex++]=arr2[j++];
        }
        delete[] arr1;
        delete[] arr2;
    }
    void mergeSort(int*arr,int s,int e){
        if(s>=e) return;

        int mid=s+(e-s)/2;
        //left side
        mergeSort(arr,s,mid);
        //right side
        mergeSort(arr,mid+1,e);

        mergeArray(arr,s,e,mid);
    }


};
int main()
{
    sort obj;
    int arr[]={5,8,10,4,11,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    // obj.quickSort(arr,0,size-1);
    obj.mergeSort(arr,0,size-1);
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}