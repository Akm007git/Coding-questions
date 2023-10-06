//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* constructionTree(int in[],int post[],int &postIndex,int inStart,int inEnd,map<int,int>&nodeToIndex, int n)
{
    if(postIndex < 0 || inStart > inEnd)
    {
        return NULL;
    }
    
    int element = post[postIndex];
    
    Node* root = new Node(element);
    
    int position = nodeToIndex[element];
    
    postIndex--;
    
    root->right = constructionTree(in,post,postIndex,position+1,inEnd,nodeToIndex,n);
    root->left = constructionTree(in,post,postIndex,inStart,position-1,nodeToIndex,n);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n-1;
    int inStart = 0;
    int inEnd = n-1;
    
    map<int,int>nodeToIndex;
    for(int i=0;i<n;i++)
    {
        nodeToIndex[in[i]] = i;
        
    }
    return constructionTree(in,post,postIndex,inStart,inEnd,nodeToIndex,n);
   
}
