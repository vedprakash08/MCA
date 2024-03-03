#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class SearchingAlgo{
    int n;
    int*arr;
    unordered_map<int,int> m;
    public:
    SearchingAlgo(int arr[],int size){
        n=size;
        this->arr=new int(n);
        for(int i=0; i<n; i++){
            this->arr[i]=arr[i];
            m[this->arr[i]]=i;
        }
    }
    //A method to perform linear search iteratively on the array 
    // it return false if not found otherwise true.
    int linearSearchIterative(int element){
        int ans=-1;
        for(int i=0; i<n; i++){
            if(this->arr[i]==element){
                ans=i;
                break;
            }
        }
        return ans;
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
        int ans=-1;
        int mid=low+(high-low)/2;

        while(low<=high){
            if(this->arr[mid]==element){
                ans=m[arr[mid]];
                break;
            }
            else if(element<this->arr[mid])
                high=mid-1;
            else
            low=mid+1; 

            mid=low+(high-low)/2;
        }
        return ans;
    }

    //A method to perform binary search recursively on the array.
    int binarySearchRecursive(int low, int high, int element){

        if(low>high){
            return -1;
        }

        int mid=low+(high-low)/2;
        if(this->arr[mid]==element){
            return m[arr[mid]];
        }

        if(this->arr[mid]<element)
        return binarySearchRecursive(mid+1,high,element);

        else
        return binarySearchRecursive(low,mid-1,element);
    }
};
int main()
{
    int n=6;
    int arr[6]={1,8,3,4,0,12};
    sort(arr,arr+n);
    SearchingAlgo obj(arr,6);
    cout<<"Element present or not "<<endl;
    cout<<obj.linearSearchIterative(4)<<endl;
    int i=0;
    cout<<obj.linearSearchRecursive(4,i)<<endl;

    cout<<obj.binarySearchIterative(41)<<endl;

    cout<<obj.binarySearchRecursive(0,n-1,3)<<endl;

   
        return 0;
}