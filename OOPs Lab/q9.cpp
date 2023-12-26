#include<iostream>
#include<vector>
using namespace std;


class matrix{
    int row,col;
    vector<vector<int>> mat;
    public:
    matrix(int r,int c): row(r),col(c), mat(row,vector<int>(col,0)){}

    // To insert an element in a matrix
    void insert( int i,int j,int data){
       if((i>=0 && i<=row) && (j>=0 && j<=col))
       mat[i][j]=data;
       else
       cout<<"Index is out of range "<<endl;
    }

    // to retreive an element from a matrix
    int retrieveElement(int i,int j){
        int element=-1;
        if((i>=0 && i<=row) && (j>=0 && j<=col))
       element= mat[i][j];
       else
       cout<<"Index is out of range "<<endl;
       return element;
    }
};
int main()
{
    matrix mat1(3,3);
    mat1.insert(0,1,3);
    mat1.insert(0,2,9);
    mat1.insert(1,1,2);
    mat1.insert(2,1,4);

    cout<<"The element is "<<mat1.retrieveElement(1,1)<<endl;
    return 0;
}