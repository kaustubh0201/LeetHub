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
    
    void inorderUtil(TreeNode* root, vector<int> &inorder){
        
        if(not root)
            return;
        
        inorderUtil(root->left, inorder);
        
        inorder.push_back(root->val);
        
        inorderUtil(root->right, inorder);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        
        inorderUtil(root, inorder);
        
        return inorder;
        
        
    }
};