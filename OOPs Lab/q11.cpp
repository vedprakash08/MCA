#include <iostream>
using namespace std;

class vector
{
    int x;
    int y;

public:
    vector() {}
    friend istream &operator>>(istream &in, vector &v1);
    friend ostream &operator<<(ostream &out, vector &v1);
    friend vector operator*(vector &v1, vector &v2);
};

// operator >> overloaded
istream &operator>>(istream &in, vector &v1)
{
    cout << "Enter the x and y component of the vector " << endl;
    in >> v1.x >> v1.y;
    return in;
}

// operator << overloaded
ostream &operator<<(ostream &out, vector &v1)
{
    cout << "The vector is " << endl;
    out << v1.x << "i + " << v1.y << "j" << endl;
    return out;
}

// operator * overloaded
vector operator*(vector &v1, vector &v2)
{
    vector res;
    res.x = v1.x * v2.x;
    res.y = v1.y * v2.y;
    return res;
}
int main()
{
    vector v1, v2, v3;
    cin >> v1;
    cout << v1;

    cin >> v2;
    cout << v2;

    v3 = v1 * v2;
    cout << v3;

    return 0;
}