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


   void  solve(TreeNode* root,vector<int>v,int k,int &count)
    {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        
        solve(root->left,v,k,count);
        solve(root->right,v,k,count);
        
        int n = v.size();
        long long  sum  = 0;
        
        for(int i = n-1;i >=0;i--)
        {
            sum += v[i];
            if(sum == k)
                count++;
        }
        v.pop_back();
      
       
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        int count =0 ;
        solve(root,v,targetSum,count);
        return count;
    }
};