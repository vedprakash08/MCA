#include<iostream>
using namespace std;

void patternA(int n){
    for(int i=0; i<n; i++){
        //print space
        for(int j=0; j<n-i-1; j++)
            cout<<" ";

        //print star
        for(int j=0; j<(2*i+1); j++)
            cout<<"*";   

        cout<<endl; 
    }
}


void patternB(int row,int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 || j==0 || i==row-1 || j==col-1)
            cout<<"#";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}

void patternC(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cout<<i;

        cout<<endl;    
    }
}


void patternD(int n){
    //upper pattern
    for(int i=0; i<n; i++){
        for(int j=0; j<(2*i+1); j++)
            cout<<"*";
        cout<<endl;    
    }
    // lower pattern
    for(int i=0; i<n-1; i++){
        for(int j=i; j<(2*(n-1)-i-1); j++)
            cout<<"*";
        cout<<endl;    
    }
}


void patternE(int n){
    for(int i=0; i<n; i++){
        //print space
        for(int j=0; j<n-i-1; j++)
            cout<<" ";

        //print star
        for(int j=0; j<(2*i+1); j++)
            cout<<"*";   
        cout<<endl; 
    }
    //reverse pattern
    for(int i=0; i<n-1; i++){
        //print space
        for(int j=0; j<=i; j++){
            cout<<" ";
        }
        //print star
        for(int j=i; j<(2*(n-1)-i-1); j++)
            cout<<"*";

        cout<<endl;    
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    patternA(n);

    // printing pattern B
    int row,col;
    cout<<"Enter  row and col"<<endl;
    cin>>row>>col;
    patternB(row,col);

    //printing pattern C
    patternC(n);


    //printing pattern D
    patternD(n);


    //printing pattern E
    patternE(n);

    return 0;
}