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
   void  printInorder(TreeNode* root,vector<int>&v)
    {
        if(!root)
        {
            return ;
        }
        
        // trevrsal
        printInorder(root->left,v);
        v.push_back(root->val);
        printInorder(root->right,v);
    }

public:
    bool isValidBST(TreeNode* root) {
         if(!root)
        {
            return true;
        }
        vector<int>v;
        
        printInorder(root,v);
        
        // check sot or not
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i] >= v[i+1])
            {
                return 0;
            }
        }
        return -1;
    }
};