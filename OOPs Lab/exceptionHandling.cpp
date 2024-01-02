#include<iostream>
using namespace std;

int main()
{
    // int a,b,c;
    // cout<<"Enter the value of a and b"<<endl;
    // cin>>a>>b;
    // try{
    //     if(b!=0){
    //         c=a/b;
    //         cout<<"The result is "<<c<<endl;
    //     }
    //     else{
    //         throw b;
    //     }
    // }
    // catch(int e){
    //     cout<<"You are dividing it by "<<e<<endl;
    // }

    int a=10;
    if(a==10)
    try{
        throw 10;
    }
    catch(int b){
        cout<<"The value is "<<b<<endl;
    }
    return 0;
}