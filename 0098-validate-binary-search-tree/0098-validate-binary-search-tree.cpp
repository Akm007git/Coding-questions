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
    bool checkings(TreeNode* root,long long int min,long long int max)
    {
        if(!root)
        {
            return true;
        }
        
        if(root->val > min && root->val < max)
        {
            bool left = checkings(root->left,min,root->val);
            bool right = checkings(root->right,root->val,max);
            
            return left && right;
        }
        else
        {
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        // Your code here
        if(!root->left && !root->right)
        {
            return 1;
        }
        long long int   min = -1000000000000;
        long long int  max = 1000000000000;
        
        return checkings(root,min,max);
    }
};