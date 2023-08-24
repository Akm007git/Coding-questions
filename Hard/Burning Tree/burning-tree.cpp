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
  public:
  
  Node* parentMapping(Node* root,int target, map<Node*,Node*>&parentToNode )
  {
      queue<Node*>q;
      q.push(root);
      Node* result = NULL; // for saving the  target node
      
      while(!q.empty())
      {
          Node* frontNode = q.front();
          q.pop();
          
          if(frontNode ->data == target)
          {
              result = frontNode;
          }
          
          if(frontNode->left)
          {
              parentToNode[frontNode->left] = frontNode; // mapping with  aprent
              q.push(frontNode->left);
          }
          if(frontNode->right)
          {
              parentToNode[frontNode->right] = frontNode; // mapping with parent
              q.push(frontNode->right);
          }
          
      }
      
      return  result;
  }
  
  
  
  int burningTree(Node* targetNode,map<Node*,Node*>&parentToNode ,int ans)
  {
     map<Node*,bool>visited;
     queue<Node*>q;
     
     // initially  push the front Node ans also it is visited
     q.push(targetNode);
     visited[targetNode] = true;
     
     while(!q.empty())
     {
         bool flag = false; // checker that in queue inserterd or not
         
         int n = q.size();
         for(int i=0;i<n;i++)
         {
             Node* frontNode = q.front();
             q.pop();
             
             
            // procwssing the extra node
            // we have to check left,right abd parent node for processing
            
            if(frontNode->left && !visited[frontNode->left])
            {
                q.push(frontNode->left);
                visited[frontNode->left] = true; // arking left when process
                flag = true;
            }
            
            // for right pointer cgecking
            
            if(frontNode->right && !visited[frontNode->right])
            {
                
                 q.push(frontNode->right);
                 visited[frontNode->right] = true; // marking  right visit after process
                 flag = true;
            }
        
            // for parent processing
            
            if(parentToNode[frontNode] && !visited[parentToNode[frontNode]])
            {
                q.push(parentToNode[frontNode]);
                visited[parentToNode[frontNode]] = true; // marking parent as visited
                
                flag = true;
            }
            
            
         }
         
         if(flag)
            ans ++;
         
     }
     return ans;
     
  }
  
  
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>parentToNode;
        Node* targetNode = parentMapping(root,target,parentToNode);
        
        int ans = 0;
        
         ans = burningTree(targetNode,parentToNode,ans);
         return ans;
        
        
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