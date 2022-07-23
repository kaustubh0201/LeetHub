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
    
    pair<bool, int> balancedUtil(TreeNode* root){
        
        if(not root){
            return {true, 0};
        }
        
        auto lh = balancedUtil(root->left);
        auto rh = balancedUtil(root->right);
        
        bool b = (abs(lh.second - rh.second) <= 1) ? true : false;
        
        if(lh.first and rh.first and b){
            return {true, (max(lh.second, rh.second) + 1)};
        }
        
        return {false, 0};        
    }
    
    bool isBalanced(TreeNode* root) {
        
        return balancedUtil(root).first;
        
    }
};