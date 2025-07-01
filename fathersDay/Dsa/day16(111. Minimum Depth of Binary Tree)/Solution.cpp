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

#include <algorithm> // For std::min
#include <queue>     // For std::queue

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
    // Recursive approach (DFS)
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // If it's a leaf node, its depth is 1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // If only right child exists, min depth is 1 + minDepth of right subtree
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // If only left child exists, min depth is 1 + minDepth of left subtree
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // If both children exist, min depth is 1 + min of depths of left and right subtrees
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }

    // Iterative approach (BFS)
    int minDepthIterative(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 1}); // Push root and its depth (1)

        while (!q.empty()) {
            TreeNode* current_node = q.front().first;
            int current_depth = q.front().second;
            q.pop();

            // If current node is a leaf, we found the minimum depth
            if (current_node->left == nullptr && current_node->right == nullptr) {
                return current_depth;
            }

            // Enqueue children with incremented depth
            if (current_node->left != nullptr) {
                q.push({current_node->left, current_depth + 1});
            }
            if (current_node->right != nullptr) {
                q.push({current_node->right, current_depth + 1});
            }
        }
        return 0; // Should not be reached if tree is valid
    }
};