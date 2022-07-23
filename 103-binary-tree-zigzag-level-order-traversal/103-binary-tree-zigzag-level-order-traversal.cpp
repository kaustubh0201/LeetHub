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
        
        vector<vector<int>> result;
        
        if(not root)
            return result;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int flag = 1;
        
        while(not q.empty()){
            
            int n = q.size();
            
            vector<int> temp;
            
            if(flag){
                
                for(int i = 0; i < n; i++){
                    
                    auto front = q.front();
                    q.pop();
                    
                    temp.push_back(front->val);
                    
                    if(front->left)
                        q.push(front->left);  
                    
                    if(front->right)
                        q.push(front->right);
                }
                
                result.push_back(temp);
                flag = 0;
            }else{
                
                for(int i = 0; i < n; i++){
                    
                    auto front = q.front();
                    q.pop();
                    
                    temp.emplace(temp.begin(), front->val);
                    
                    if(front->left)
                        q.push(front->left);
                    
                    if(front->right)
                        q.push(front->right);
                    
                }
                
                result.push_back(temp);
                flag = 1;               
            }
            
        }
        
        return result;
        
    }
};