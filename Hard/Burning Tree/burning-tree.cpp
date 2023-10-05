//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    
private:
    
Node* createMapping(unordered_map<Node*,Node*>&mp, Node* root, int start)
{
    Node* target = NULL;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* frontNode = q.front();
        q.pop();

        if(frontNode->data  == start )
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
    int minTime(Node* root, int target) 
    {
        // Your code goes here
         // create parrent to node mapping
        unordered_map<Node*,Node*>parentToNode; // for keep trace  to all three side

        // step:1 create parent --> node mapping  &&  finding the target node
        Node* targetNode = createMapping(parentToNode,root,target);

        // step 2: traverse BFS from the start node and burn tree left,right,parent at a single time
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0 ;

        while(!q.empty())
        {
            bool flag = false; // checker that after one full iretation(left,right,parent), insertion of queue or not

            int size = q.size();

            for(int i=0;i<size;i++)
            {
                Node* frontNode = q.front();
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

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends