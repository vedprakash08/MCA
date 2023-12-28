#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int lineCount = 0;
    ifstream obj("sample.txt");
    string str;
    string strToFind = "submit";
    bool ans = false;
    while (getline(obj, str))
    {
        lineCount++;
        if (str.find(strToFind) != string::npos)
        {
            ans = true;
            obj.close();
        }
    }
    obj.close();
    if (ans)
        cout << "The line in which the string present is " << lineCount << endl;
    else
        cout << "The string is not present" << endl;
    return 0;
}