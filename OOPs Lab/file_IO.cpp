#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream x("testing.txt");

    string ci;
    //getline(cin,ci);
    int count = 0;

    while(x.eof()==0){
while(getline(x,ci,' ')){
        count++;
        
    }
    }
    
    cout << count;
    
    x.close();
    // ifstream obj("testing.txt");
    // string s;
    // getline(obj,s);
    // cout<<s;
    return 0;
}