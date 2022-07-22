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
    
    bool mirrorUtil(TreeNode* t1, TreeNode* t2){
        
        if(not t1 and not t2)
            return true;
        
        if((not t1 and t2) or (t1 and not t2))
            return false;
        
        if(t1->val == t2->val){
            bool l = mirrorUtil(t1->left, t2->right);
            bool r = mirrorUtil(t1->right, t2->left);
            
            return (l and r);
        }
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return mirrorUtil(root->left, root->right);
        
    }
};