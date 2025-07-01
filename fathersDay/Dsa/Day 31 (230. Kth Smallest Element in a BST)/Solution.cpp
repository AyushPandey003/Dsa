#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

    int KthSmallest(TreeNode* root, int k) {
        std::vector<int> sorted_elements;
        inorder(root, sorted_elements);
        if (k > 0 && k <= sorted_elements.size()) {
            return sorted_elements[k - 1];
        }
        return -1; // Or throw an exception
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution solution;
    int k = 1;
    int result = solution.KthSmallest(root, k);
    std::cout << result << std::endl; // Output: 1
    return 0;
}
