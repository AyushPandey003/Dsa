#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* SearchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        } else if (val < root->val) {
            return SearchBST(root->left, val);
        } else {
            return SearchBST(root->right, val);
        }
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    TreeNode* result = solution.SearchBST(root, val);
    if (result) {
        std::cout << result->val << std::endl; // Output: 2
    } else {
        std::cout << "Value not found in the BST" << std::endl;
    }
    return 0;
}
