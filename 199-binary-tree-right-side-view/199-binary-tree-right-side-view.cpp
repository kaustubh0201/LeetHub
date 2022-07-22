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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        
        if(not root)
            return result;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(not q.empty()){
            
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                
                auto front = q.front();
                q.pop();
                
                if(i == n - 1){

                    result.push_back(front->val);
                    
                }
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
                
            }
            
        }
        
        return result;
        
    }
};