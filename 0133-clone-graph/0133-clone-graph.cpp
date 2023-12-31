/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    if(!node)
    {
        return NULL;
    }
    unordered_map<Node*,Node*>visited;

    queue<Node*>q;
    q.push(node);

    visited[node] = new Node(node->val);

    while( !q.empty())
    {
        Node* frontNode = q.front();
        q.pop();

        for(auto it : frontNode->neighbors)
        {
            if(!visited.count(it))
            {
                q.push(it);
                visited[it] = new Node(it->val);

            }
            visited[frontNode]->neighbors.push_back(visited[it]);
        }
        
    }
    return visited[node];
   
   

  



        
    }
};