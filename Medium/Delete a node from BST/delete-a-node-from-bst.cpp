//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to delete a node from BST.

Node* findMax(Node* root)
{
    Node* temp = root;
    while( temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}


Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL)
        return root;
        // if we got the elemnt

    if(root->data == X )
    {
        // 4 edge case will be apperaed
         
         //1. all child is NULL basically leaf node
         if(root->left == NULL && root->right == NULL )
         {
             delete root;
             return NULL;
         }
         
         //2. only left child no right child
         if(root->left != NULL && root->right == NULL )
         {
             return root->left;
         }
         
         //3. only right child no left
         if(root->right != NULL && root->left == NULL)
         {
             return root->right;
         }
         
         //4. both left and right are available
         
         if(root->left != NULL && root->right != NULL)
         {
             // finding the max element from left or min element from the right then delete
             int maxi = findMax(root->left)->data ;// store the maxvalue from the left;
             root->data = maxi;
             
             root->left = deleteNode(root->left,maxi);
             return root;
         }
    }
    else if(root->data > X)
    {
       root->left = deleteNode(root->left,X);
        
    }
    else
    {
        root->right = deleteNode(root->right,X);
    }
}
