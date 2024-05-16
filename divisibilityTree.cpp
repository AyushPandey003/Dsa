// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.

// Example 1:

// Input: 
// n = 10
// edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
// Output:
// 2
// Explanation:
// Original tree:
// After removing edge 1-3 and 1-6, each remaining component consists of even number of nodes. 


// Example 2:

// Input: 
// n = 4
// edges = {{2,1},{4,2},{1,3}}
// Output:
// 1
// Explanation:
// After removing 2-1, each remaining component consists of even number of nodes. 
// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function minimumEdgeRemove() which takes n and edges as input parameters and returns the maximum number of edges that need to be removed from the given tree.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= n <= 105
// edges.length == n - 1
// 1 <= edges[i][0], edges[i][1] <= n

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj; // Adjacency list for the tree
    vector<int> subtreeSize; // To store the size of each subtree
    int removableEdges; // Count of removable edges
    
    void dfs(int node, int parent) {
        subtreeSize[node] = 1; // Each node counts as one

        // Process all children (i.e., connected nodes except the parent)
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node);
                subtreeSize[node] += subtreeSize[child];

                // Check if the subtree rooted at 'child' has an even number of nodes
                if (subtreeSize[child] % 2 == 0) {
                    removableEdges++; // This edge can be removed
                }
            }
        }
    }

    int minimumEdgeRemove(int n, vector<vector<int>> &edges) {
        adj.assign(n + 1, vector<int>());
        subtreeSize.assign(n + 1, 0);
        removableEdges = 0;

        // Construct the adjacency list from edges
        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize DFS from the root node, which is assumed to be node 1
        dfs(1, 0);

        // The result is the count of removable edges
        return removableEdges;
    }
};
