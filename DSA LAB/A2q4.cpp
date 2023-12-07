#include<iostream>
using namespace std;
/* D. Write a program to transpose a given 2-D matrix. */

void transpose(int mat[3][3],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int temp=mat[i][j];
            mat[j][i]=mat[i][j]^mat[j][i];
            mat[i][j]=mat[i][j]^mat[j][i];
            mat[j][i]=temp;
        }
    }
    cout<<"Transpose of a matrix is "<<endl;
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
    transpose(mat,n);
    return 0;
}