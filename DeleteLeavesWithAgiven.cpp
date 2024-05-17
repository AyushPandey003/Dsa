#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void pre(int target, TreeNode* &root) {
        if (!root) return;
        pre(target, root->left);
        pre(target, root->right);
        if (root->val == target && !root->left && !root->right) {
            delete root;  // delete the node to free memory
            root = nullptr;  // set the pointer to nullptr
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        pre(target, root);
        return root;
    }
};

// Helper function to print the tree in-order for testing purposes
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Example usage
    Solution solution;

    // Create the tree for example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->right->left = new TreeNode(2);
    root1->right->right = new TreeNode(4);

    // Print the original tree
    cout << "Original tree (in-order): ";
    inorder(root1);
    cout << endl;

    // Remove leaf nodes with target value 2
    root1 = solution.removeLeafNodes(root1, 2);

    // Print the resulting tree
    cout << "Modified tree (in-order): ";
    inorder(root1);
    cout << endl;

    return 0;
}
