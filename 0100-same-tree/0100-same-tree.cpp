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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        
         //Your Code here
        if(!r1 && !r2 )
            return true;
            
        else if( r1 && !r2)
        {
            return false;
        }
        else if(!r1 && r2)
        {
            return false;
        }
        
       
        
        // traverse left and right
        
        bool left =  isSameTree(r1->left,r2->left);
        bool right =  isSameTree(r1->right, r2->right);
         if(left && right && r1->val == r2->val)
         {
             return true;
         }
         else
         {
             return false;
         }
    }
};