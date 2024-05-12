#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int>rank,parent,size;
    public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node]) return node;

        return parent[node]=findPar(parent[node]);
    }

    //union by rank
    void unionByRank(int u,int v){
        int ult_u=findPar(u);
        int ult_v=findPar(v);
        if(ult_u==ult_v) return;
        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }

    //union by size-->. no differenec in btween rank and size but union by size is much more intuitive
    void unionBySize(int u,int v){
        int ult_u=findPar(u);
        int ult_v=findPar(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]+=size[ult_u];
        }
    }

};
int main()
{
    Disjoint d1(7);
    d1.unionBySize(1,2);   
    d1.unionBySize(2,3);   
    d1.unionBySize(4,5);   
    d1.unionBySize(6,7);   
    d1.unionBySize(5,6);
    if(d1.findPar(1)==d1.findPar(7)) {
        cout<<"same"<<endl;
    }  
    else{
        cout<<"not same"<<endl;
    }
    d1.unionBySize(3,7);
    if(d1.findPar(1)==d1.findPar(7)) {
        cout<<"same"<<endl;
    }  
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}