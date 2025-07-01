#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

void inorder_traversal(TreeNode* node) {
    if (node) {
        inorder_traversal(node->left);
        std::cout << node->val << " ";
        inorder_traversal(node->right);
    }
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 5;
    TreeNode* result = solution.insertIntoBST(root, val);
    inorder_traversal(result);
    std::cout << std::endl;
    return 0;
}
