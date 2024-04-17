#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    int count; // number of connected components
    
    UnionFind(int n) : count(n), parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; // union
            count--;
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1; // Not enough edges to connect all nodes
    
    UnionFind uf(n);
    
    for (const auto& conn : connections) {
        uf.unite(conn[0], conn[1]);
    }
    
    return uf.count - 1; // Need (count-1) additional connections
}
int main() {

    int n ;
    cout<<"Enter number of workstations"<<endl;
    cin>>n; //no. of workstations
    int m; //no. of connections
    cout<<"Enter no. of connections"<<endl;
    cin>>m;
    cout<<"Enter the connections as pairs of integers:"<<endl;
    vector<vector<int>> connections ;
    for(int i=0;i<m;i++){
        int ai, bi;
        std::cin >> ai >> bi;
        connections.push_back({ai, bi});
    }

    int result = makeConnected(n, connections);

    cout << "Minimum number of connections needed: " << result << endl;

    return 0;
}
