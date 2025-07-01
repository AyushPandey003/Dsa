#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        std::vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return build_bst(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build_bst(const std::vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = build_bst(nums, l, m - 1);
        node->right = build_bst(nums, m + 1, r);
        return node;
    }
};

void print_bst(TreeNode* node) {
    if (!node) return;
    print_bst(node->left);
    std::cout << node->val << " ";
    print_bst(node->right);
}

int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    Solution solution;
    TreeNode* result = solution.sortedListToBST(head);
    print_bst(result);
    std::cout << std::endl;
    return 0;
}
