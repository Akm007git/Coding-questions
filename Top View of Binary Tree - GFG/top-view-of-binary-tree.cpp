//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans; // for saving the answer;
        
        map<int,int>mp; // for one to one mapping horizontal distanece with node data
        queue<pair<Node*,int> >q; // store node, with its horizontal dist
        
        q.push(make_pair(root,0)) ;// as initial middle horizontal  dist is zero
        
        while(!q.empty())
        {
            pair<Node*,int>p=q.front();
            q.pop();
            
            // extract the pair
            Node* frontNode = p.first;
            int horzDist = p.second;
            
            if(mp.find(horzDist) == mp.end()) // it means no maooing avilable with horz distence
            {
                mp[horzDist] = frontNode->data;
            }
            
            // traverse
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left,horzDist-1)); // distem=nce kom jsbe 
            }
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right,horzDist+1));
            
        }
        // // after this we got the  one to one  mapping  with horzdistence and the node data
        
        for(auto it : mp)
        {
        ans.push_back(it.second);    
        }
        return ans;
        
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends