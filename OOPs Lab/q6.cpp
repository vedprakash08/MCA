#include<iostream>
using namespace std;

class Complex{
    int real;
    int img;
    public:
    Complex(int a,int b){
        real=a;
        img=b;
    }

    friend Complex sumComplex(Complex o1, Complex o2);
    friend void print(Complex o);
};

Complex sumComplex(Complex o1, Complex o2){
    int a=o1.real+o2.real;
    int b=o2.img+o1.img;
    Complex o3(a,b);
    return o3;
}
void print(Complex o){
    cout<< "The complex  number is "<<o.real<<" + "<<o.img<<"i"<<endl; 
}
int main()
{
    Complex o1(3,4);
    Complex o2(4,5);
    Complex o3=sumComplex(o1,o2);
    print(o3);
    return 0;
}