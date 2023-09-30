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
    pair<bool,int> checkBalance(TreeNode* root)
{
    if(!root)
    {
        pair<bool,int>p = make_pair(true,0);
         // initially bool, height
        return p;
    }

    pair<bool,int>left = checkBalance(root->left);
    pair<bool,int>right = checkBalance(root->right);

    int  lh = left.second;
    int  rh = right.second;

    int diff = abs(lh-rh);

    pair<bool,int>ans; // for returning the next step
    

    if(left.first && right.first && diff <=1) // if all three condition are true;
    {
        ans.first = true;
        ans.second = max(lh,rh)+1; // return as a height of tree
        
    }
    else{
        ans.first= false;
       
    }

    return ans;
}

public:


    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
};