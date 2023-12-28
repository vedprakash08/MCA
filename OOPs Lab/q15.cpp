#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream obj("temp.csv");
    if (!obj.is_open())
    {
        cout << "file is not open" << endl;
    }

    string str;
    while (getline(obj, str))
    {
        istringstream ss(str);
        string s;
        while (getline(ss, s, ','))
        {
            cout << s << setw(5) << " ";
        }
        cout << endl;
    }
    return 0;
}