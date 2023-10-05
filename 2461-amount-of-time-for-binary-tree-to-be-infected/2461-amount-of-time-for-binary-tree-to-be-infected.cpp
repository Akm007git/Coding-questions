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

TreeNode* createMapping(unordered_map<TreeNode*,TreeNode*>&mp, TreeNode* root, int start)
{
    TreeNode* target = NULL;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* frontNode = q.front();
        q.pop();

        if(frontNode->val  == start )
        {
            target = frontNode;
        }
        // left and right traversal
        if(frontNode->left)
        {
            q.push(frontNode->left);
            mp[frontNode->left] = frontNode;
        }
        if(frontNode->right)
        {
            q.push(frontNode->right);
            mp[frontNode->right] = frontNode;
        }

    }
    return target;
}

public:
    int amountOfTime(TreeNode* root, int start) {
        // create parrent to node mapping
        unordered_map<TreeNode*,TreeNode*>parentToNode; // for keep trace  to all three side

        // step:1 create parent --> node mapping  &&  finding the target node
        TreeNode* targetNode = createMapping(parentToNode,root,start);

        // step 2: traverse BFS from the start node and burn tree left,right,parent at a single time
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0 ;

        while(!q.empty())
        {
            bool flag = false; // checker that after one full iretation(left,right,parent), insertion of queue or not

            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();

                // treverse 3 direction if posible LEFT,RIGHT,PARENT
                if(frontNode->left && !visited[frontNode->left])
                {
                    visited[frontNode->left] = true;
                    q.push(frontNode->left);
                    flag = true;

                }
                if(frontNode->right && !visited[frontNode->right])
                {
                    visited[frontNode->right] = true;
                    q.push(frontNode->right);
                    flag = true;

                }
                if(parentToNode[frontNode] && !visited[parentToNode[frontNode]])
                {
                    visited[parentToNode[frontNode]] = true;
                    q.push(parentToNode[frontNode]);
                    flag = true;
                }

            }
            if(flag == true)
                {
                    time++;
                }
        }
        return time;


    }
};