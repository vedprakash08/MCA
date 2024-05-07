#include<iostream>
#include<ctime>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

class sort{
    public:
    /***************Bubble Sort*************************/
    
    void bubbleSort(int*arr,int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    

    /***************Insertion Sort*************************/
     void insertionSort(int *arr,int n){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j>0;j--){
                if(arr[j]<arr[j-1]){
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
            }
        }
    }

    /***************Selection Sort*************************/

    int findMax(int nums[],int idx,int size){
        int maxx=0;
        for(int i=0;i<=size-idx-1;i++){
            if(nums[i]>nums[maxx]) maxx=i;
        }
        return maxx;
    }
    void selecionSort(int *arr,int n){
        for(int i=0;i<n;i++){
            int max=findMax(arr,i,n);
            //lets swap the curr max with the last element
            int temp=arr[max];
            arr[max]=arr[n-i-1];
            arr[n-i-1]=temp;
        }
    }

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
void tester(){
int size[]={10,100,500,1000,5000,10000,50000,100000};
 for(int j=0;j<9;j++){
    int n=size[j];
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    sort s;
    auto before=high_resolution_clock::now();
    // s.bubbleSort(arr,n);
    // s.insertionSort(arr,n);
    // s.selecionSort(arr,n);
    // s.quickSort(arr,0,n-1);
    // s.mergeSort(arr,0,n-1);
    s.heapSort(arr,n);
    auto after=high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(after-before);
    cout<<"Time for "<<n<<" = "<<duration.count()<<endl;

 }
 
}

int main(){
    tester();
    
     return 0;
}