// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

 

// Example 1:


// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
// Example 2:


// Input: root = [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= n <= 100
// 0 <= Node.val <= n
// The sum of all Node.val is n.


#include <iostream>
#include <cmath>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
    
private:
    int dfs(TreeNode* node, int& moves) {
        if (!node) return 0;

        // Traverse left and right children
        int left_balance = dfs(node->left, moves);
        int right_balance = dfs(node->right, moves);
        
        // Update the total moves required
        moves += abs(left_balance) + abs(right_balance);
        
        // Return the current node's balance
        return node->val + left_balance + right_balance - 1;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = node->right = nullptr;
    return node;
}

// Main function to test the solution
int main() {
    Solution solution;

    // Example 1: [3,0,0]
    TreeNode* root1 = newNode(3);
    root1->left = newNode(0);
    root1->right = newNode(0);
    std::cout << "Moves required: " << solution.distributeCoins(root1) << std::endl;  // Output: 2

    // Example 2: [0,3,0]
    TreeNode* root2 = newNode(0);
    root2->left = newNode(3);
    root2->right = newNode(0);
    std::cout << "Moves required: " << solution.distributeCoins(root2) << std::endl;  // Output: 3

    return 0;
}
