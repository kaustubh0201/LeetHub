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
    
    pair<int, int> diameterUtil(TreeNode* root){
        
        if(not root){
            return {0, 0};
        }
        
        auto ldiameter = diameterUtil(root->left);
        auto rdiameter = diameterUtil(root->right);
        
        pair<int,int> p;
        p.second = (max(ldiameter.second, rdiameter.second) + 1);
        
        p.first = max(ldiameter.second + rdiameter.second + 1, max(ldiameter.first, rdiameter.first));    
        
        return p;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameterUtil(root).first - 1;
        
    }
};