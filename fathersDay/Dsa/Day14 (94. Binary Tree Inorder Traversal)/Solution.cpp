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

#include <vector>
#include <stack>

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
    // Recursive approach
    void inorderHelper(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorderHelper(node->left, result);
        result.push_back(node->val);
        inorderHelper(node->right, result);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    /*
    // Iterative approach (using a stack)
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            // Traverse left subtree and push nodes onto stack
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            // Pop node, add its value to result, and move to right subtree
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
    */
};
