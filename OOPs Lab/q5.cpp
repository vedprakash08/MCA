#include <iostream>
using namespace std;

class class_2;
class class_1
{
    int num1;

public:
    class_1(int num1)
    {
        this->num1 = num1;
    }
    friend void swap(class_1 &o1, class_2 &o2);
    friend void getData(class_1 &o1, class_2 &o2);
};

class class_2
{
    int num2;

public:
    class_2(int num2)
    {
        this->num2 = num2;
    }
    friend void swap(class_1 &o1, class_2 &o2);
    friend void getData(class_1 &o1, class_2 &o2);
};

void swap(class_1 &o1, class_2 &o2)
{
    int temp = o1.num1;
    o1.num1 = o2.num2;
    o2.num2 = temp;
}
void getData(class_1 &o1, class_2 &o2)
{
    cout << "The value of num1 is " << o1.num1 << " and "
         << " num2 is " << o2.num2 << endl;
}
int main()
{
    class_1 o1(10);
    class_2 o2(16);

    getData(o1, o2);
    swap(o1, o2);
    getData(o1, o2);
    return 0;
}