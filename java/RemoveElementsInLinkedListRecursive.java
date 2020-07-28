/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
     public ListNode removeElements(ListNode head, int val) {
        if(head == null) return head;
        ListNode h = removeElements(head.next, val);
        
        if(head.val == val) return h;
        else head.next = h;
        
        return head;
    }
}
