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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        TreeNode* curr = root;
        
        stack<TreeNode*> stk;
        
        while((curr) or (not stk.empty())){
            
            while(curr){
                
                stk.push(curr);
                curr = curr->left;
                
            }
            
            curr = stk.top();
            stk.pop();
            
            result.push_back(curr->val);
            
            curr = curr->right;           
        }
        
        return result;
        
    }
};