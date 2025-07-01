#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = LowestCommonAncestor(root->left, p, q);
        TreeNode* right = LowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* p = root->left; // Node 5
    TreeNode* q = root->left->right->right; // Node 4
    Solution solution;
    TreeNode* lca = solution.LowestCommonAncestor(root, p, q);
    if (lca) {
        std::cout << "LCA is " << lca->val << std::endl; // Output: 5
    }
    return 0;
}
