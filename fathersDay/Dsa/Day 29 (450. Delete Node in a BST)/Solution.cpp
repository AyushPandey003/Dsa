#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* min_larger_node = getMin(root->right);
            root->val = min_larger_node->val;
            root->right = deleteNode(root->right, min_larger_node->val);
        }
        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};

void print_inorder(TreeNode* node) {
    if (!node) return;
    print_inorder(node->left);
    std::cout << node->val << " ";
    print_inorder(node->right);
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    int key = 3;
    root = solution.deleteNode(root, key);
    print_inorder(root);
    std::cout << std::endl;
    return 0;
}
