#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            std::vector<int> level_nodes;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_nodes.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(level_nodes);
        }
        return result;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> result = solution.levelOrder(root);
    for (const auto& level : result) {
        std::cout << "[";
        for (size_t i = 0; i < level.size(); ++i) {
            std::cout << level[i] << (i == level.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
    // Expected Output:
    // [1]
    // [2, 3]
    // [4, 5, 6, 7]
    return 0;
}
