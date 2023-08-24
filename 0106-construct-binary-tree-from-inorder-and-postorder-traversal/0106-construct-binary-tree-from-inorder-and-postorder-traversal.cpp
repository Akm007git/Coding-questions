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

    TreeNode* constructTree(vector<int>postorder,int &postorderIndex,int inStartIndex,int inEndIndex, int n ,                                                                       unordered_map<int,int>&mp)
    {
        if(postorderIndex < 0 || inStartIndex > inEndIndex)
            return NULL;

        int element = postorder[postorderIndex--]; /// first access the last elementas root from postorder
        
        TreeNode* root = new TreeNode(element);
        //finding position in inorderw
        int pos = mp[element]; // found the  index

        root->right = constructTree(postorder,postorderIndex,pos+1,inEndIndex,n,mp);
        root->left = constructTree(postorder,postorderIndex, inStartIndex, pos-1,n,mp);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = postorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i; // mapping the in order array
        }

        int postorderIndex = n-1;
        int inStartIndex = 0;
        int inEndIndex = n-1;

        TreeNode* ans = constructTree(postorder,postorderIndex,inStartIndex,inEndIndex,n,mp);
        return ans;
    }
};