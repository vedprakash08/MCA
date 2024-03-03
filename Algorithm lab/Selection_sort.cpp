#include<iostream>
using namespace std;

void selection(int arr[],int size){
    for(int i=0; i<size; i++){
        int ele=arr[i];
        int index=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<ele){
                index=j;
                ele=arr[j];
            }
        }
        swap(ele,arr[index]);
    }
}
void bubble(int arr[],int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertion(int arr[],int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j>0; j--){
            if(arr[j]<arr[j-1])
            swap(arr[j],arr[j-1]);
        }
    }
}
int main()
{
    int size;
    cout<<"Enter the size of an array"<<endl;
    cin>>size;
    int*arr=new int[size];
    cout<<"Enter the element of the array"<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    // selection(arr,size);
    // bubble(arr,size);
    insertion(arr,size);
    cout<<"SORTED ARRAY"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<", ";
    }
    return 0;
}