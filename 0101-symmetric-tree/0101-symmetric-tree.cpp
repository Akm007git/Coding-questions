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
private:
bool checking(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) // if both are null 
        {
            return true;
        }
        if(!root1 || !root2) // if any one are null
        {
            return false;
        }
        if(root1->val != root2->val)
        {
            return false;
        }
        
        
        return checking(root1->left, root2->right) && 
        checking(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        
	    if(!root)
	    {
	        return true;
	    }
	    TreeNode* leftRoot = root->left;
	    TreeNode* rightRoot = root->right;
	    
	    return checking(leftRoot,rightRoot);
    }
};