#include<iostream>
#include<vector>
using namespace std;

class matrix{
    int row,col;
    vector<vector<int>> mat;
    public:
    matrix(){}
    matrix(int r,int c): row(r),col(c), mat(row,vector<int>(col,0)){}

    // To insert an element in a matrix
    void insert( int i,int j,int data){
       if((i>=0 && i<=row) && (j>=0 && j<=col))
       mat[i][j]=data;
       else
       cout<<"Index is out of range "<<endl;
    }

    void display(){
        cout<<"The matrix is "<<endl;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // + overloaded
    matrix operator+(matrix &m){
        matrix res(m.row,m.col);
        cout<<"The addition of the matrix is "<<endl;
        for(int i=0; i<m.row; i++){
            for(int j=0; j<m.col; j++){
                res.mat[i][j]=mat[i][j]+m.mat[i][j];
            }
        }
        return res;
    }

    // * operator
    matrix operator *(matrix &m){
        matrix res(this->row,m.col);
        cout<<"The multiplication of the matrix is "<<endl;
        for(int i=0; i<this->row; i++){
            for(int j=0; j<m.col; j++){
                for(int k=0; k<this->col; k++){
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return res;
    }

    // comparison operator
    bool operator ==(matrix &m){
        for(int i=0; i<m.row; i++){
            for(int j=0; j<m.col; j++){
                if(mat[i][j]!=m.mat[i][j])
                return false;
            }
        }
        return true;
    }

    bool operator !=(matrix &m){
        for(int i=0; i<m.row; i++){
            for(int j=0; j<m.col; j++){
                if(mat[i][j]!=m.mat[i][j])
                return true;
            }
        }
        return false;
    }
};
int main()
{
    matrix m1(2,2), m2(2,2),m3,m4;
    m1.insert(0,0,4);
    m1.insert(0,1,5);
    m1.insert(1,0,2);
    m1.insert(1,1,9);

    m2.insert(0,0,5);
    m2.insert(0,1,-3);
    m2.insert(1,0,1);
    m2.insert(1,1,2);

    m1.display();
    m2.display();
    m3=m1+m2;
    m3.display();

    m4=m1*m2;
    m4.display();
    if(m1==m2)
    cout<<"Matrix are equal"<<endl;
    else if(m1!=m2)
    cout<<"Matriz are not equal"<<endl;
    return 0;
}