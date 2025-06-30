# include <iostream>
using namespace std;
#include <unordered_map>

int countPairsWithSumK(int arr[], int n, int k) {
    int count = 0;
    std::unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        count += freq[complement];
        freq[arr[i]]++;
    }
    return count;
}
int main(){
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << countPairsWithSumK(arr, n, k);
    return 0;
}