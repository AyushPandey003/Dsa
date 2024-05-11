#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> worker(n);

        for (int i = 0; i < n; ++i) {
            worker[i] = {wage[i] / (double) quality[i], quality[i]};
        }

        sort(worker.begin(), worker.end());

        double result = 1e9;
        double qsum = 0.0;
        priority_queue<int> pq;

        for (int i = 0; i < n; ++i) {
            int q = worker[i].second;
            qsum += q;
            pq.push(q);

            if (pq.size() > k) {
                qsum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                result = min(result, qsum * worker[i].first);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    cout.precision(5);
    cout << fixed << sol.mincostToHireWorkers(quality, wage, k) << endl;
    return 0;
}

// 857. Minimum Cost to Hire K Workers
// Solved
// Hard
// Topics
// Companies
// There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

// We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

// Every worker in the paid group must be paid at least their minimum wage expectation.
// In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
// Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: quality = [10,20,5], wage = [70,50,30], k = 2
// Output: 105.00000
// Explanation: We pay 70 to 0th worker and 35 to 2nd worker.