#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DS{
    public:
    // number--> index
    unordered_map<int,int> numToIndex;
    vector<int> v;

    //function to insert an element x into the DS
    void insert(int x){
        if(numToIndex.find(x)!=numToIndex.end()){
            cout<<"The number is already present"<<endl;
        }
        else{
            v.push_back(x);
            int idx=v.size();

            numToIndex[x]=idx-1;
        }
    }

    //Removes an item x from the data structure if present.
    void remove(int x){
        if(numToIndex.find(x)==numToIndex.end()){
            cout<<"The number is not present"<<endl;
        }
        else{
            int eleIndex=numToIndex[x];
            int lastEleIndex=v.size()-1;

            // swap elements
            swap(v[lastEleIndex],v[eleIndex]);

            //change index of lastEleIndex in map
            numToIndex[v[lastEleIndex]]=eleIndex;

            //erase that element from map and vector
            numToIndex.erase(x);
            v.pop_back();
        }
    }

    //Searches an item x in the data structure. and return its Index
    int search(int x){
        //ele is  not present
        if(numToIndex.find(x)==numToIndex.end()){
            cout<<"The number is not present ";
            return -1;
        }

        else{
            cout<<"The index of element "<<x<< " is ";
            return numToIndex[x];
        }
    }

    //Returns a random element from current set of elements
    int getRandom(){
        if(v.size()==0) return -1;
        int getRandomIndex=rand()%v.size();
        cout<<"The random Number is ";
        return v[getRandomIndex];
    }

};
// int main()
// {
//     DS obj;
//     obj.insert(4);
//     obj.insert(90);
//     obj.insert(5);
//     obj.insert(23);
//     // obj.remove(5);
//     cout<<obj.search(5)<<endl;
//     cout<<obj.getRandom();
//     // cout<<"jsgcd";
//     return 0;
// }


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
// #include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int n=3;
string s="abc";
void solve(int idx,string temp){
    ans.push_back(temp);
    if(idx==n){
        // temp.pop_back();
        // temp.erase();
        return;
    }
    for(int i=idx; i<n; i++){
        temp+=s[i];
        solve(i+1,temp);
        temp.pop_back();
    }
}
int main()
{
    string temp;
    solve(0,temp);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].length(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
