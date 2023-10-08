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
    TreeNode* findMaxx(TreeNode* root)
{
    while(root->right)
    {
        root = root->right;
    }
    return root;
}


public:
    TreeNode* deleteNode(TreeNode* root, int X) {
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->val == X)
    {
        //  case, if it it is leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        //2nd case , if there single child left or child
        
         if(root->left && !root->right)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
         if(root->right && !root->left)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        
        //3rd  if therse are two child available
        if (root->right!=NULL && root->left!=NULL)
        {
            int  maxi = findMaxx(root->left)->val;  // finding max from the left or also we can save mi from tright
            root->val = maxi;
            root->left = deleteNode(root->left,maxi);
            return root;
            
        }

    }
    
    else if(root->val < X)
    {
        root->right = deleteNode(root->right,X);
        return root;
    }
    else
    {
        root->left = deleteNode(root->left,X);
        return root;
    }
    return root;

    }
};