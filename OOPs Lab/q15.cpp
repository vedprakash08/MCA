#include<iostream>
#include<vector>
#include <sstream>
#include<fstream>
using namespace std;

int main()
{
    ifstream obj("temp.csv");
    if(!obj.is_open()){
        cout<<"file is not open"<<endl;
    }

    string str;
    while(getline(obj,str)){
       istringstream ss;
       while (getline(str,ss,',')){
        
       }
       
    }
    return 0;
}