// Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
// A component of the graph is good if and only if the component is fully connected.
// Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 

// Example 1:

// Input: 


// e=3 
// v=3
// edges={{1, 2},{1, 3},{3, 2}}
// Output: 
// 1
// Explanation: 
// We can see that there is only one component in the graph and in this component there is a edge between any two vertces.


#include <vector>
#include <iostream>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> size;
    vector<int> edgeCount; // To keep track of the number of edges in each component
    
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            edgeCount[a] += edgeCount[b]; // Merge edge counts
        }
    }
    
public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>>& edges) {
        parent.resize(v);
        size.resize(v, 1);
        edgeCount.resize(v, 0); // Initial edge count is zero
        
        iota(parent.begin(), parent.end(), 0); // Fill parent with 0, 1, 2, ..., v-1
        
        for (const auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            unionSet(u, v);
            edgeCount[find(u)]++; // Increment edge count for the component representative
        }
        
        int goodComponents = 0;
        for (int i = 0; i < v; ++i) {
            if (find(i) == i) { // Check if i is a representative
                int nodes = size[i];
                int edgesInComponent = edgeCount[i];
                if (edgesInComponent == (nodes * (nodes - 1)) / 2) {
                    goodComponents++;
                }
            }
        }
        
        return goodComponents;
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}};
    Solution sol;
    int goodComponents = sol.findNumberOfGoodComponent(3, 3, edges);
    cout << "Number of good components: " << goodComponents << endl;
    return 0;
}
