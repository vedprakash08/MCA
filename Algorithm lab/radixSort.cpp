#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int digitsInMaxEle(vector<int>&arr){
    int maxi=arr[0];
    for(int i=1; i<arr.size(); i++){
        maxi=max(maxi,arr[i]);
    }
    int count=0;
    while(maxi){
        count++;
        maxi/=10;
    }
    return count;
}
void radixSort(vector<int>&arr,vector<vector<int>>&ans){
    int digits = digitsInMaxEle(arr);
    int exp=1;
    for(int i=0; i<digits; i++){
        for(int j=0; j<arr.size(); j++){
            ans[(arr[j]/exp)%10].push_back(arr[j]);
        }
        arr.clear();
        for(int j=0; j<10; j++){
            for(int k=0; k<ans[j].size(); k++){
                arr.push_back(ans[j][k]);
            }
            ans[j].clear();
        }
        exp*=10;
    }
}
int main()
{
    vector<int> arr = {803, 127, 45, 75, 144, 49, 18, 2, 7};
    vector<vector<int>>ans(10);
    radixSort(arr,ans);
    for(auto it: arr) cout<<it<<" ";
    cout<<endl;
    return 0;
}