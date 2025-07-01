#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }

private:
    bool isBST(TreeNode* node, long long low, long long high) {
        if (!node) {
            return true;
        }
        if (node->val <= low || node->val >= high) {
            return false;
        }
        return isBST(node->left, low, node->val) && isBST(node->right, node->val, high);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution solution;
    bool result = solution.isValidBST(root);
    std::cout << (result ? "True" : "False") << std::endl; // Output: True
    return 0;
}
