#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, vector<pair<int, int>>> adj;
    void insert(int u,int v,int wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    void print(){
        for(auto it: adj){
            cout<<it.first<<" -->";
            for(auto i:  it.second){
                cout<<"["<<i.first<<","<<i.second<<"]";
            }
            cout<<endl;
        }
    }
};

int main() {
    graph g;
    // g.insert(0,1,2);
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
    g.print();

    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    vector<int> visited(n, 0);
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<pair<int, pair<int, int>>> mst;

    pq.push({0, {0, -1}});
    int sum=0;
    while(!pq.empty()) {
        auto front_ele = pq.top();
        pq.pop();
        int node = front_ele.second.first;
        if(!visited[node]) {
            mst.push_back({front_ele.first, {front_ele.second.second, front_ele.second.first}});
            visited[node] = 1;
            sum+=front_ele.first;
            for(auto neigh : g.adj[node]) {
                int neighNode=neigh.first;
                int edgwt=neigh.second;
                if(!visited[neighNode]){
                    pq.push({edgwt,{neighNode,node}});
                }
            }
        }
        
    }
    cout<<"Mst weight is : "<<sum<<endl;

    for(auto it : mst) {
        cout << it.second.second<<"-->"<<"["<<it.second.first<<","<<it.first<<"]"<<endl;
    }
    return 0;
}