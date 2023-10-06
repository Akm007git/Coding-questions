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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
        {
            return ans;
        }
        TreeNode* current = root;
        while(current != NULL)
        {
            if(current->left == NULL)
            {
                ans.push_back(current->val);
                current = current->right;
            }
            else
            {
                TreeNode* pred = current->left;
                
                // go to the extreme right 
                while(pred->right != NULL && pred->right != current)
                {
                    pred = pred->right;
                }

                // if temporary already not exists
                if( pred->right == NULL) // no temporary exists
                {
                    pred->right = current;
                    current = current->left;
                }
                else // temp linkn exists
                {
                    pred->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }

            }
        }
        return ans;
    }
};