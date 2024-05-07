#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void insert(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
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

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Graph G;
    G.insert(0, 1, 4);
    G.print();
    return 0;
}