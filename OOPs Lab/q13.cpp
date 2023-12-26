#include <iostream>
#include <fstream>
using namespace std;
// program to find number of words and lines in a file
int main()
{
    int wordCount = 0;
    int lineCount = 0;
    ifstream obj("sample.txt");
    string str;

    while (getline(obj, str))
    {
        lineCount++;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                wordCount++;
        }
        wordCount++;
    }

    cout << "The number of line in the file is: " << lineCount << endl;
    cout << "The number of word in the file is: " << wordCount << endl;
    return 0;
}