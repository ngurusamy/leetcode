# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return head
        h = self.removeElements(head.next, val)
        
        if head.val == val:
            return h
        else:
            head.next = h
        return head


 
