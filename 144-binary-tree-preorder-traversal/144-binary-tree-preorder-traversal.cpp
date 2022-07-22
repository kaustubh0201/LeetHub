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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        if(not root)
            return result;
        
        stack<TreeNode*> stk;
        stk.push(root);        
        
        while(not stk.empty()){
            
            auto top = stk.top();
            stk.pop();
            
            result.push_back(top->val);
            
            if(top->right)
                stk.push(top->right);
            
            if(top->left)
                stk.push(top->left);            
        }
        
        return result;
        
    }
};