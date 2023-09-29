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

void  printInorder(TreeNode* root,vector<int>&in)
{
    stack<TreeNode*>st;
   
    
    
    while(1)
    {
       
        if(root != NULL)
        {
             st.push(root);
            root = root->left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            root = st.top();
            
            in.push_back(root->val);
            st.pop();
            root = root->right;
        }
    }
   

}



public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>in;
         printInorder(root,in);
         return in;
        
        
    }
};