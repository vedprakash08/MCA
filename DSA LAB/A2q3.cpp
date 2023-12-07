#include<iostream>
using namespace std;

/* C. Write C++ program that adds two 2-D matrices and prints the result. */

void add2Dmatrix(int mat1[3][3],int mat2[3][3],int mat3[3][3],int row,int col){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int mat1[3][3]={{4,7,3},{5,2,7},{8,4,2}};
    int mat2[3][3]={{9,30,23},{6,3,2},{6,3,2}};
    int row=3,col=3;

    int mat3[3][3];
    add2Dmatrix(mat1,mat2,mat3,row,col);

    cout<<"The addition of two matrix is "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}