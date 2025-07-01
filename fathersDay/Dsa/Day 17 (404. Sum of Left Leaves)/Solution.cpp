#include <cstddef> // For NULL or nullptr

// Definition for a binary tree node.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sumL = 0;

        // Check if the left child exists and is a leaf node
        if (root->left && !root->left->left && !root->left->right) {
            sumL += root->left->val;
        }

        // Recursively call for left and right subtrees
        sumL += sumOfLeftLeaves(root->left);
        sumL += sumOfLeftLeaves(root->right);

        return sumL;
    }
};

// Example usage (for testing purposes, not part of the class)
/*
#include <iostream>
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(4); // Example of a left leaf

    std::cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(root) << std::endl; // Expected: 9 + 4 = 13

    // Clean up memory (important in C++)
    // This is a simple example, for a real application, consider smart pointers or a proper tree destructor.
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/
