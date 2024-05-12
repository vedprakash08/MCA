#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void insert(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});
    }

    void print() {
        for(auto it : adj) {
            cout << it.first << " --> ";
            for(auto i : it.second) {
                cout << "[" << i.first << ", " << i.second <<  "]";
            }
            cout << endl;
        }
    }
};
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
int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Graph g;
    g.insert(0, 1, 4);
    g.insert(0, 7, 8);
    g.insert(1, 2, 8);
    g.insert(1, 7, 11);
    g.insert(2, 8, 2);
    g.insert(2, 3, 7);
    g.insert(2, 5, 4);
    g.insert(3, 4, 9);
    g.insert(3, 5, 14);
    g.insert(4, 5, 10);
    g.insert(5, 6, 2);
    g.insert(6, 7, 1);
    g.insert(6, 8, 6);
    g.insert(7, 8, 7);
    // g.print();

    //storing edges to sort according to the weight
    // {wt,{u,v}}
    vector<pair<int,pair<int,int>>> edges;

    for(auto it:g.adj){
        int node=it.first;
        for(auto i: it.second){
            int adjNode=i.first;
            int wt=i.second;
            edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(),edges.end());
    Disjoint d1(n);
    int mstWeight=0;
    for(int i=0; i<edges.size(); i++){
        int wt=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;

        if(d1.findPar(u)!=d1.findPar(v)){
            mstWeight+=wt;
            d1.unionBySize(u,v);
        }
    }
    cout<<"The mst weight is "<<mstWeight<<endl;
    
    return 0;
}