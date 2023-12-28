#include <iostream>
using namespace std;
class num2;
class num1
{
    int n1;

public:
    num1(int n1)
    {
        this->n1 = n1;
    }
    friend int getMax(num1 o1, num2 o2);
};

class num2
{
    int n2;

public:
    num2(int n2)
    {
        this->n2 = n2;
    }
    friend int getMax(num1 o1, num2 o2);
};

int getMax(num1 o1, num2 o2)
{
    return o1.n1 > o2.n2 ? o1.n1 : o2.n2;
}
int main()
{
    num1 o1(3);
    num2 o2(4);
    cout << getMax(o1, o2) << endl;
    return 0;
}