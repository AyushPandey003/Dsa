#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();

            if (current->right) {
                s.push(current->right);
            }
            if (current->left) {
                s.push(current->left);
            }

            if (!s.empty()) {
                current->right = s.top();
            }
            current->left = nullptr;
        }
    }
};

void print_flattened_list(TreeNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    solution.flatten(root);
    print_flattened_list(root);
    return 0;
}
