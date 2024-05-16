#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool evaluateNode(TreeNode* node) {
    // Check if node is a leaf node
    if (node == nullptr) {
        return false;  // or true, depending on your implementation
    }

    if (node->val == 0 || node->val == 1) {  // Leaf node
        return node->val;
    }

    // Evaluate left and right children
    bool leftValue = evaluateNode(node->left);
    bool rightValue = evaluateNode(node->right);

    // Apply boolean operation based on node value
    if (node->val == 2) {  // OR operation
        return leftValue || rightValue;
    } else if (node->val == 3) {  // AND operation
        return leftValue && rightValue;
    }
    return false;  // Default return value
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    bool result = evaluateNode(root);
    cout << boolalpha << result << endl;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root;

    return 0;
}