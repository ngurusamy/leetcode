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
    

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        vector<vector<int>> result;
        
        deque<TreeNode *> Q;
        Q.push_back(root);
        bool reverse = true;
        
        while(!Q.empty()) {
            vector<int> level_nodes;
            deque<TreeNode*> dQ;
            int count = Q.size();
            
            for(int i = 0; i < count; i++) {
                TreeNode * n = Q.front();
                level_nodes.push_back(n->val);
                Q.pop_front();
                
                if(reverse) {
                    if(n->left) dQ.push_front(n->left);
                    if(n->right) dQ.push_front(n->right);
                } else {
                    if(n->right) dQ.push_front(n->right); 
                    if(n->left) dQ.push_front(n->left);
                }
            }
            result.push_back(level_nodes);
            Q.insert(Q.end(), dQ.begin(), dQ.end());
            reverse = !reverse;
        }
        
        return result;
    }
};
