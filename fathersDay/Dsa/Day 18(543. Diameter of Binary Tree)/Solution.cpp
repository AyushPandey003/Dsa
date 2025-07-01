#include <algorithm> // For std::max
#include <iostream>  // For example usage
#include <queue>     // For example usage (if needed for tree construction)

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
    int diameter; // Class member to store the maximum diameter found

    int depth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left_depth = depth(node->left);
        int right_depth = depth(node->right);

        // Update the diameter at this node
        diameter = std::max(diameter, left_depth + right_depth);

        // Return the depth of the tree rooted at this node
        return std::max(left_depth, right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0; // Initialize diameter for each call
        depth(root);
        return diameter;
    }
};

// Example usage (optional, for testing purposes)
/*
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    std::cout << "Diameter: " << sol.diameterOfBinaryTree(root) << std::endl; // Expected: 3

    // Clean up memory (important in C++)
    // This is a simple example, for complex trees, a proper destructor or helper function is needed
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/