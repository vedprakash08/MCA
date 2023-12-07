#include<iostream>
using namespace std;

/* E. Write a C++ program to traverse a given 2-D matrix. */
void traverse(int mat[3][3],int n){
        cout<<"The matrix is "<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
}

int main()
{
    int mat[3][3]={{4,7,3},{5,2,7},{8,4,2}};
    int n=3;
    traverse(mat,n);
    return 0;
}