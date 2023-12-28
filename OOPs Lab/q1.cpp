#include <iostream>
using namespace std;

class temp
{
    static int count;

public:
    temp()
    {
        count++;
    }
    static void showCount()
    {
        cout << "The number of objects is " << count << endl;
    }
};
int temp::count;
int main()
{
    temp t1, t2, t3;
    temp::showCount();
    return 0;
}