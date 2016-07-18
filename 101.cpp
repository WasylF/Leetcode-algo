/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymetric(root->left, root->right);
    }
    
    bool isSymetric(TreeNode* leftRoot, TreeNode* rightRoot)
    {
        if (!leftRoot || !rightRoot) 
            return leftRoot == rightRoot;
        
        if (leftRoot -> val != rightRoot -> val)
            return false;
            
        return isSymetric(leftRoot->left , rightRoot->right) && 
            isSymetric(leftRoot->right , rightRoot->left);
    }
};
