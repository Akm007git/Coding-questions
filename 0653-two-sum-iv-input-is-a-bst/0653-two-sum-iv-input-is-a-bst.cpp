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
    void printInorder(TreeNode* root, vector<int>&v)
    {
        if(root == NULL)
        {
            return;
        }

        printInorder(root->left,v);
        v.push_back(root->val);
        printInorder(root->right,v);

    }


    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        printInorder(root,v);
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++)
        {
            int a = v[i];
            int b = k - a;

            if(mp.find(b) != mp.end())
                return true;
            else
                mp[v[i]]++;
        }
        return false;
    }
};