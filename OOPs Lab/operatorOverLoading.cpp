#include<iostream>
using namespace std;

class complex{
    int real;
    int imag;
    public:
    complex(){}
    complex(int r,int i): real(r), imag(i){}

    // operator overloading
    complex operator +(complex o){
        complex res;
        res.real=real+o.real;
        res.imag=imag+o.imag;
        return res;
    }
    void print();
};
void complex::print(){
    cout<<"The number is "<<real<<" + "<<imag<<"i"<<endl;
}

class weight{
    int kg=0;
    public:

    // void operator ++(){
    //     ++kg;
    // }

    weight operator ++(){
        weight temp;
        temp.kg=kg++;
        return temp;
    }
    void operator ++(int){
        kg++;
    }
    void print(){
        cout<<"The weight is "<<kg<<endl;
    }
};
int main()
{
    // complex c1(5,6);
    // complex c2(4,6);
    // complex c3;
    // c3=c1+c2; // c1.add(c2);
    // c3.print();


    weight obj, obj1;
    ++obj;
    obj.print();
    obj++;
    obj.print();

    // obj1=obj++;// this will give error because above fi=unction is not of return type
    obj1=++obj;
    obj1.print();
    return 0;
}