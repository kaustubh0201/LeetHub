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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        if(not root)
            return result;
        
        stack<TreeNode*> stk;
        
        TreeNode* curr = root;
        
        while(curr or not stk.empty()){
            
            if(curr){
                
                stk.push(curr);
                curr = curr->left;
                
            }else{
                
                TreeNode* temp = stk.top()->right;
                
                if(not temp){
                    
                    temp = stk.top();
                    stk.pop();
                    
                    result.push_back(temp->val);
                    
                    while(not stk.empty() and temp == stk.top()->right){
                        temp = stk.top();
                        stk.pop();
                        
                        result.push_back(temp->val);
                        
                    }
    
                }
                else{
                    curr = temp;
                }
                
            }
            
        }
        
        return result;
        
    }
};