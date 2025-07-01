/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <cstddef> // For nullptr

// Definition for a binary tree node (if not provided by LeetCode environment)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if root is null, there's no path, return false.
        if (root == nullptr) {
            return false;
        }
        
        // Subtract current node's value from targetSum
        targetSum -= root->val;
        
        // If it's a leaf node and targetSum is 0, we found a path
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }
        
        // Recursively check left and right subtrees
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};