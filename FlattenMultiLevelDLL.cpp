/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node * flatLL(Node * head)
    {
        Node * curr = head, * tail = head;
        
        while(curr)
        {
            Node * child = curr->child;
            Node * next = curr->next;
            
            if(child)
            {
                Node * _tail = flatLL(child);
                _tail->next = next;
                if(next)
                    next->prev = _tail;
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                curr = _tail;
            }
            else
                curr = next;
            
            if(curr)
                tail = curr;
        }
        return tail;
    }
    
public:
    Node* flatten(Node* head) {
        if(head) 
            flatLL(head);
        return head;
        
    }
};
