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

TreeNode* constructTree(vector<int>preorder,int &preIndex,int inStartIndex, int inEndIndex,unordered_map<int,int>&mp,int n)
{
    if(preIndex >= n || inStartIndex > inEndIndex)
        return NULL;



    int element = preorder[preIndex++];
    TreeNode* root = new TreeNode(element);
    int position = mp[element];

    root->left = constructTree(preorder,preIndex,inStartIndex,position-1,mp,n);
     root->right = constructTree(preorder,preIndex,position+1,inEndIndex,mp,n);
     return root;

}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;

        }

        int preIndex = 0 ;
        int inStartIndex = 0;
        int n = preorder.size();
        int inEndIndex = inorder.size()-1;

        return constructTree(preorder,preIndex,inStartIndex,inEndIndex,mp,n);
    }
};