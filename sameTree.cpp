/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isSameTree_rec(TreeNode * p, TreeNode * q) {
        if(p == NULL && q == NULL)
            return true;
        
        if(p != NULL  && q != NULL) {
            return (p->val == q->val && isSameTree_rec(p->left, q->left) && isSameTree_rec(p->right, q->right));
        }
            /*return false;
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);*/
        
        return false;
        
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isSameTree_rec(p, q);
    }
};
