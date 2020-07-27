/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * current = head, * prev = NULL;
        
        if(head == NULL)
            return head;
        
        while(current != NULL) {
            
            if(current->val == val){
                if(prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                ListNode * tmp = current;
                current = current->next;
                delete(tmp);
            } 
            else
            {
                prev = current;
                current = current->next;
            }            
        }
        return head;
    }
};
