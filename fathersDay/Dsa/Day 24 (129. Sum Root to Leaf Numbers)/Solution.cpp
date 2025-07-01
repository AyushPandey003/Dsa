#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current_sum) {
        if (!node) {
            return 0;
        }
        current_sum = current_sum * 10 + node->val;
        if (!node->left && !node->right) {
            return current_sum;
        }
        return dfs(node->left, current_sum) + dfs(node->right, current_sum);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int result = solution.sumNumbers(root);
    std::cout << result << std::endl; // Output: 25
    return 0;
}
