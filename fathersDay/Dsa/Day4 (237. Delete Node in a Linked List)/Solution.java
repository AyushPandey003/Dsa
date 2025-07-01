/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        // According to the problem constraints, the given node will not be the tail node
        // and will always be a valid node in the list.
        // No need to handle null node or tail node explicitly based on problem statement.
        
        // Copy the value of the next node to the current node
        node.val = node.next.val;
        
        // Link the current node to the node after the one being deleted
        node.next = node.next.next;
    }
}