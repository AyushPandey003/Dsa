// Given a binary tree root and an integer target, delete all the leaf nodes with value target.

// Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

// Example 1:



// Input: root = [1,2,3,2,null,2,4], target = 2
// Output: [1,null,3,null,4]
// Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
// After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
// Example 2:



// Input: root = [1,3,3,3,2], target = 3
// Output: [1,3,null,null,2]
// Example 3:



// Input: root = [1,2,null,2,null,2], target = 2
// Output: [1]
// Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// 1 <= Node.val, target <= 1000


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
