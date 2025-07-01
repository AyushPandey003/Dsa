#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> ZigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;

        while (!q.empty()) {
            int level_size = q.size();
            std::vector<int> level_values(level_size);
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_values[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (!left_to_right) {
                std::reverse(level_values.begin(), level_values.end());
            }
            result.push_back(level_values);
            left_to_right = !left_to_right;
        }
        return result;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> result = solution.ZigzagLevelOrder(root);

    for (const auto& level : result) {
        std::cout << "[";
        for (size_t i = 0; i < level.size(); ++i) {
            std::cout << level[i] << (i == level.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
    // Expected Output:
    // [3]
    // [20, 9]
    // [15, 7]
    return 0;
}
