#include<iostream>
using namespace std;
/* F. Write a program to traverse a 2D matrix in a spiral order and return the elements. */

void spiralPrint(int mat[3][3],int row,int col){

    int sR=0;
        int sC=0;
        int eR=row-1;
        int eC=col-1;
        //Total element
        int total= row*col;
        int count=0;
        cout<<"The spiral print of an array is "<<endl;
        while(count<total){
            //Printing first row
            for(int i=sC;count<total && i<=eC; i++ ){
                cout<<mat[sR][i]<<" ";
                count++;
            }
            sR++;
            //last col
            for(int i=sR; count<total && i<=eR;i++){
                cout<<mat[i][eC]<<" ";
                count++;
            }
            eC--;
            //last row
            for(int i=eC; count<total && i>=sC; i--){
                cout<<mat[eR][i]<<" ";
                count++;
            }
            eR--;
            // first col
            for(int i=eR; count<total && i>=sR; i--){
                cout<<mat[i][sC]<<" ";
                count++;
            }
            sC++;
        }
}
int main()
{
    int mat[3][3]={{4,7,3},{5,2,7},{8,4,2}};
    int row=3;
    int col=3;
    spiralPrint(mat,row,col);

    return 0;
}