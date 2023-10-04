/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void creatingParentMapping(unordered_map<TreeNode*,TreeNode*>&mp, TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);

        while( !q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left)
                {
                    q.push(frontNode->left);
                    mp[frontNode->left] = frontNode; // mapping the node with its parrent
                }

                if(frontNode->right)
                {
                    q.push(frontNode->right);
                    mp[frontNode->right] = frontNode;
                }
            }
        }
    }


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parentToNode; // create parent to node mapping;
        creatingParentMapping(parentToNode,root); // function for creating map node--->parent
        
        // keep trace the node is visited or not
        unordered_map<TreeNode*,bool>visited;

        queue<TreeNode*>q;
        q.push(target); // traverse BFS from the target node level wise
        visited[target] = true; // initially startinh node  will be true
        int level = 0;

        while( !q.empty())
        {
            int size = q.size();
            
            if(level  == k) // while cheking level wise from the target
            {  
                break;
            }

            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();

                // traverse to the three diretion left, right , parent
                if(frontNode->left && !visited[frontNode->left])
                {
                    visited[frontNode->left] = true;
                    q.push(frontNode->left);

                }
                if(frontNode->right && !visited[frontNode->right])
                {
                    visited[frontNode->right] = true;
                    q.push(frontNode->right);
                }
                if(parentToNode[frontNode] && !visited[parentToNode[frontNode]])
                {
                    visited[parentToNode[frontNode]] = true;
                    q.push(parentToNode[frontNode]);
                }
            }
            level++;
            
        }

        // all necessary elements now present in the queue

        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
};