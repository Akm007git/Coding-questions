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
void preorderItterative(TreeNode* root , vector<int>&pre)
{

    if(root == NULL)
    {
        return;
    }

    stack<TreeNode*>st;
    st.push(root);


    while(!st.empty())
    {
        
        TreeNode* front = st.top();
        st.pop();
        //. print the first node
        pre.push_back(front->val);

        if(front->right)
        {
            st.push(front->right);
        }

        if(front->left)
        {
            st.push(front->left);
        }
    }




}


public:
    vector<int> preorderTraversal(TreeNode* root) {
        
    vector<int>pre;

    preorderItterative(root,pre);
    return pre;
    }
};