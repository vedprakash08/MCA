#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v={5,3,4,7,2,6,2,3,5};
    int size=v.size();
    vector<int> count(7);
    for(int i=0; i<size; i++){
        count[v[i]-1]++;
    }
    for(int i=1; i<7; i++){
        count[i]+=count[i-1];
    }

    vector<int>ans(size);
    for(int i=0; i<size; i++){
        ans[count[v[i]-1]-1]=v[i];
        count[v[i]-1]--;
    }
    for(int i=0; i<size; i++) cout<<ans[i]<<" ";
    return 0;
}