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
    TreeNode* insertionNode(TreeNode* root,TreeNode* newNode )
    {
        if(!root)
        {
            return NULL;
        }
       
            if(root->right == NULL && root->val <  newNode->val)
            {
                root->right = newNode;
                newNode->right = NULL;
           
            }
            if(root->left == NULL && root->val > newNode->val )
            {
                root->left = newNode;
                newNode->left = NULL;
            }

            if(root->val > newNode->val)
            {
                root->left = insertionNode(root->left,newNode);
            }
            if(root->val < newNode->val)
            {
                root->right = insertionNode(root->right,newNode);
            }
            return root;

    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
        TreeNode* newNode = new TreeNode(val);
         if(!root)
        {
            return newNode;
        }
        newNode = insertionNode(root,newNode);
        return newNode;

    }
};