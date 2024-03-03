#include<iostream>
using namespace std;
class sort{
    public:
    /***************Quick Sort*************************/
    int partitionIndex(int start,int end,int*arr){
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


/**************************** Heap Sort ************************************************/
void heapify(int*arr,int size,int idx){
    
    int largest=idx;
    int leftChild=(2*idx)+1;
    int rightChild=(2*idx)+2;

        if(leftChild<size && arr[leftChild]>arr[largest]){
            largest=leftChild;
        }
        if(rightChild<size && arr[rightChild]>arr[largest]){
            largest=rightChild;
        }
        if(largest!=idx){
            swap(arr[largest],arr[idx]);
            heapify(arr,size,largest);
        }
}
void buildHeap(int*arr,int size){

    for(int i=(size/2)-1; i>=0; i--){
        heapify(arr,size,i);
    }
}

void heapSort(int*arr,int size){
    buildHeap(arr,size);
    while(size>0){
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,size,0);
    }
}
};
int main()
{
    sort obj;
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int*arr=new int[size];
    cout<<"Enter the element of the array"<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int type=0;
    cout<<"Enter the type of sorting "<<endl;
    cout<<"1. Quick sort"<<endl;
    cout<<"2. Merge sort"<<endl;
    cout<<"3. Heap sort"<<endl;
    cin>>type;
    switch (type)
    {
    case 1:
        obj.quickSort(arr,0,size-1);
        break;
    case 2:
        obj.mergeSort(arr,0,size-1);
        break;
    case 3:
        obj.heapSort(arr,size);
        break;
    default:
        break;
    }
    cout<<"SORTED ARRAY IS "<<endl;
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}