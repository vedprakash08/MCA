#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    // string name;
    // ofstream obj("sample.txt");
    // cout<<"Enter your name "<<endl;
    // getline(cin, name);
    // obj<<"My name is " +name;

    // obj.close();

    // ifstream oin("sample.txt"); ->opening file using contructor
    ifstream oin;
    oin.open("sample.txt");
    // to read multiple line we eof->end of file
    while(oin.eof()==0){
        string st;
        getline(oin,st);
        cout<<st<<endl;;
    }
    
    return 0;
}