# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        current, prev = head, None
        
        if head == None:
            return head
        
        while current != None :
            
            if current.val == val :
                if prev == None :
                    head = current.next
                else:
                    prev.next = current.next
            else:
                prev = current
                
            current = current.next
            
        return head
 
