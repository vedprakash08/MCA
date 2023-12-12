#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int rot;
    cout<<"Enter number of rotation"<<endl;
    cin>>rot;
    // 1 rotation in every iteration
    for(int i=0; i<n-rot; i++){
        int temp=arr[0];
        for(int j=0; j<n-1; j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
    cout<< "Printing the rotated array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}