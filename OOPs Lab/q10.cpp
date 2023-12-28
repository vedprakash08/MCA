#include <iostream>
using namespace std;

class complex
{
    int real;
    int imag;

public:
    complex() {}
    complex(int r, int i) : real(r), imag(i) {}

    // addition oftwo complex number
    complex operator+(complex obj)
    {
        complex ans;
        ans.real = real + obj.real;
        ans.imag = imag + obj.imag;
        return ans;
    }

    // multiplication of two number
    complex operator*(complex obj)
    {
        complex ans;
        ans.real = (real * obj.real) - (imag * obj.imag);
        ans.imag = (real * obj.imag) + (obj.real * imag);
        return ans;
    }

    void print()
    {
        cout << "The complex number is " << real << " + " << imag << "i" << endl;
    }
};
int main()
{
    complex c1(4, 5), c2(5, 6), c3, c4;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "The addition of two complex number is" << endl;
    c3.print();
    cout << "The multiplication of two number is" << endl;
    c4.print();
    return 0;
}