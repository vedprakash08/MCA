#include<iostream>
using namespace std;

class SearchingAlgo{
    int n;
    int*arr;
    public:
    SearchingAlgo(int arr[],int size){
        n=size;
        this->arr=new int(n);
        for(int i=0; i<n; i++){
            this->arr[i]=arr[i];
        }
    }
    //A method to perform linear search iteratively on the array it return -1 if not found otherwise the index of that element
    int linearSearchIterative(int element){
        int index=-1;
        for(int i=0; i<n; i++){
            if(this->arr[i]==element){
                index=i;
                break;
            }
        }
        return index;
    }


    // A method to perform linear search recursively on the array.
    int linearSearchRecursive(int element, int &i){
        if(this->arr[i]==element)
        return i;
    
    // recursive call if not found
        i++;
        return linearSearchRecursive(element,i);
    }


    //A method to perform binary search iteratively on the array
    int binarySearchIterative(int element){
        int low=0;
        int high=n-1;
        int index=-1;
        int mid=low+(high-low)/2;

        while(low<=high){
            if(this->arr[mid]==element){
                index=mid;
                break;
            }
            else if(element<this->arr[mid])
                high=mid-1;
            else
            low=mid+1; 

            mid=low+(high-low)/2;
        }
        return index;
    }

    //A method to perform binary search recursively on the array.
    int binarySearchRecursive(int low, int high, int element){

        if(low>high){
            return -1;
        }

        int mid=low+(high-low)/2;
        if(this->arr[mid]==element){
            return mid;
        }

        if(this->arr[mid]<element)
        return binarySearchRecursive(mid+1,high,element);

        else
        return binarySearchRecursive(low,mid-1,element);
    }
};
int main()
{
    int n=5;
    int arr[5]={1,2,3,4,5};
    SearchingAlgo obj(arr,5);

    cout<<obj.linearSearchIterative(3)<<endl;
    int i=-1;
    cout<<obj.linearSearchRecursive(3,i)<<endl;

    cout<<obj.binarySearchIterative(4)<<endl;

    cout<<obj.binarySearchRecursive(0,n-1,4)<<endl;
    // obj.print();
    return 0;
}