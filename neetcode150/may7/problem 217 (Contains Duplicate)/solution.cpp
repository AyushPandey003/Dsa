#include <iostream>
using namespace std;


bool containsDuplicate(int* nums, int numsSize) {
    int hashTable[100000] = {0}; 

    for (int i = 0; i < numsSize; i++) {
        hashTable[nums[i]]++;
        if (hashTable[nums[i]] > 1) {
            return true;
        }
    }
    return false;
}
int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    bool result = containsDuplicate(nums, size);
    cout << (result ? "Contains duplicate" : "No duplicates") << endl;
    return 0;
}