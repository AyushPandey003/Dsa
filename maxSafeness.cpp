#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using namespace std;
#include <climits> 

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> nearest_one_distance(n, vector<int>(n, INT_MAX));
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<pair<int,int>> directions{{1,0}, {0,1}, {-1,0}, {0,-1}};

        // Multi-source BFS to find minimum distance to nearest '1' for each cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    pq.push({0,{i,j}});
                    nearest_one_distance[i][j] = 0;
                }
            }
        }

        while(!pq.empty()) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
            for(auto dir : directions) {
                int ni = dir.first + i;
                int nj = dir.second + j;
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && dist+1 < nearest_one_distance[ni][nj]) {
                    nearest_one_distance[ni][nj] = dist + 1;
                    pq.push({dist+1, {ni,nj}});
                }
            }
        }

        // BFS from (0,0) to (n-1,n-1) to determine the maximum safeness factor
        priority_queue<pair<int,pair<int,int>>> pq1;
        int safenessfactor = -1;
        pq1.push({nearest_one_distance[0][0],{0,0}});
        vector<vector<int>> visited(n,vector<int>(n,0));
        while(!pq1.empty()) {
            int i = pq1.top().second.first;
            int j = pq1.top().second.second;
            safenessfactor = pq1.top().first;
            pq1.pop();
            if(i==n-1 && j==n-1){
                return safenessfactor;
            }
            for(auto dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj]) {
                    pq1.push({min(nearest_one_distance[ni][nj], safenessfactor), {ni,nj}});
                    visited[ni][nj] = 1;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << "Max Safeness (Example 1): " << sol.maximumSafenessFactor(grid1) << endl; // Output should be 0

    vector<vector<int>> grid2 = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    cout << "Max Safeness (Example 2): " << sol.maximumSafenessFactor(grid2) << endl; // Output should be 2

    vector<vector<int>> grid3 = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    cout << "Max Safeness (Example 3): " << sol.maximumSafenessFactor(grid3) << endl; // Output should be 2

    return 0;
}
