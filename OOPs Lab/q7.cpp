#include<iostream>
using namespace std;

class temp{
    int data;
    public:
    temp(int v):data(v){};

    // copy constructor
    temp(temp &obj){
        cout<<"Copy constructor is called"<<endl;
        data=obj.data;
    }
    void getData(){
        cout<<"The data is "<<data<<endl;
    }
};
int main()
{
    temp o1(8);
    temp o2=o1;
    // temp o2(o1);

    o1.getData();
    o2.getData();
    return 0;
}