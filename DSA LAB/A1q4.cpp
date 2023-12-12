#include<iostream>
using namespace std;
// Swap function two swap two elements in an array
void swap(int &a, int &b){
    int temp=a;
    // using xor operator 
    b=a^b;
    a=b^a;
    b=temp;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int i=0,j=n-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++; j--;
    }

    cout<< "Reverse array is "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}