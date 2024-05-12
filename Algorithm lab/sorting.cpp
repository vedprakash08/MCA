#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Sort{
    vector<int>v;
    int size;
    public:
    Sort(vector<int>&vec,int size){
        v.resize(size);
        this->size=size;
        for(int i=0; i<size; i++){
            v[i]=vec[i];
        }
    }
    //Insertion sort
    void insertionSort(){
        for(int i=1; i<size; i++){
            int key=v[i];
            int j=i-1;
            while(j>=0 && key<v[j]){
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=key;
        }
    }

    //selection sort
    void selection(){
        for(int i=0; i<size-1; i++){
            int mini=INT_MAX;
            int minIndex=0;
            for(int j=i; j<size; j++){
                if(v[j]<mini){
                    mini=v[j];
                    minIndex=j;
                }
            }
            swap(v[i],v[minIndex]);
        }
    }

    //bubble sort
    void bubble(){
        for(int i=0; i<size-1; i++){
            bool flag=true;
            for(int j=0; j<size-i-1; j++){
                if(v[j]>v[j+1]){
                    flag=false;
                    swap(v[j],v[j+1]);
                }
            }
            if(flag) break;
        }
    }

    //quick sort
    int findPivotIndex(int start,int end){
        int pivot=start;
        int i=start+1,j=end;
        while(i<=j){
            while(i<=end && v[i]<=v[pivot]) i++;
            while(j>=0 && v[j]>v[pivot]) j--;
            if(i<j)
            swap(v[i],v[j]);
        }
        swap(v[j],v[pivot]);
        return j;
    }
    void quick(int start,int end){
        if(start>=end) return;
        int pivotIndex=findPivotIndex(start,end);
        quick(start,pivotIndex-1);
        quick(pivotIndex+1,end);
    }


    //merge sort
    void mergeSortedArray(int start,int end, int mid){
        int len1=mid-start+1;
        int len2=end-mid;
        vector<int> temp1(len1),temp2(len2);
        for(int i=0; i<len1; i++) temp1[i]=v[start+i];
        for(int i=0; i<len2; i++) temp2[i]=v[mid+1+i];

        int i=0,j=0;
        int mainIndex=start;    
        while(i<len1 && j<len2){
            if(temp1[i]<=temp2[j]){
                v[mainIndex++]=temp1[i++];
            }
            else{
                v[mainIndex++]=temp2[j++];
            }
        }

        while(i<len1){
            v[mainIndex++]=temp1[i++];
        }
        while(j<len2){
            v[mainIndex++]=temp2[j++];
        }

        temp1.clear();
        temp2.clear();
    }
    void mergeSort(int start,int end){
        if(start>=end) return;
        int mid=start+(end-start)/2;
        mergeSort(start,mid);
        mergeSort(mid+1,end);
        mergeSortedArray(start,end,mid);
    }


    //heap sort
    void heapify(int idx){
        int largest=idx;
        int leftChild=2*idx+1;
        int rightChild=2*idx+2;

        if(leftChild<size && v[leftChild]>v[largest]){
            largest=leftChild;
        }
        if(rightChild<size && v[rightChild]>v[largest]){
            largest=rightChild;
        }

        if(largest!=idx){
            swap(v[largest],v[idx]);
            heapify(largest);
        }
    }

    void buildHeap(){
        for(int i=size/2-1; i>=0; i--){
            heapify(i);
        }
    }

    void heapSort(){
        buildHeap();
        while(size>0){
            swap(v[0],v[size-1]);
            size--;
            heapify(0);
        }
    }

    
    //print
    void print(){
        cout<<"The array is "<<endl;
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    vector<int> vec={67,2,90,34,56,56,12,100,4,79,303,56,45};
    int size=vec.size();
    Sort obj(vec,size);

    // obj.insertionSort();
    // obj.selection();
    // obj.bubble();
    // obj.quick(0,size-1);
    // obj.mergeSort(0,size-1);
    obj.heapSort();
    obj.print();
    return 0;
}