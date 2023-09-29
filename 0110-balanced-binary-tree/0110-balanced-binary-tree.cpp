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

// extracting the heights of each part one by one
private:
int heights(TreeNode* root)
{
    if(!root) return 0;

    int left = heights(root->left);
    int right = heights(root->right);

    return max(left,right)+1;
}

public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        // main condition

        int diff = abs(heights(root->left) - heights(root->right));

        if(left && right && diff <=1) // if all the 3 cond. will be true
            return true;
        else
            return false;
    }
};