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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
    {
        return 0;
    }
    queue<pair<TreeNode*,long long int>>q;
    q.push({root,0}); //initially the node will be root, and  the width is 0
    int ans = 0;

    while( !q.empty())
    {
        int size= q.size();
        int min = q.front().second; // for handeling the overflow case
        int leftmost,rightmost;

        for(int i=0;i<size;i++)
        {
            TreeNode* frontNode = q.front().first;
            long long int curr_index = q.front().second - min; // main trick for handleing the inteher overflow
            q.pop();

            if(i==0) // trigger for first iteration
            {
                leftmost = curr_index;
            }
            if(i==size-1) // trigger forn last iteration
            {
                rightmost = curr_index;
            }

            // traversal left right
            if(frontNode->left)
            {
                q.push({frontNode->left,2*curr_index+1}); // for leftpart traversal
            }
            if(frontNode->right)
            {
                q.push({frontNode->right, 2 * curr_index + 2});
            }
        }
         ans = max(ans,rightmost-leftmost+1);
    }
        return ans;
    }
};