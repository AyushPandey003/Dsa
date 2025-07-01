/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // According to the problem constraints, the given node will not be the tail node
        // and will always be a valid node in the list.
        // However, for robustness, we can add checks:
        if (node == nullptr || node->next == nullptr) {
            // Cannot delete if node is null or it's the last node
            // (as we need to copy from node->next)
            return;
        }
        
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        
        // Store the node to be deleted (the next node)
        ListNode* nodeToDelete = node->next;
        
        // Link the current node to the node after the one being deleted
        node->next = node->next->next;
        
        // Free the memory of the deleted node (important in C++)
        delete nodeToDelete;
    }
};