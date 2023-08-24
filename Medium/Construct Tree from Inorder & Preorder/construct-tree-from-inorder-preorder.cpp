//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int findPos(int in[],int n,int element)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i] == element)
            {
                in[i] = INT_MAX;
                return i;
            }
        }
    }
    
    
    
    
    Node* constructingTree(int pre[],int &preIndex,int inStartIndex,int inEndIndex,int n,int in[])
    {
        if(preIndex >= n || inStartIndex > inEndIndex)
            return NULL;
        
        int element = pre[preIndex++];
        Node* root = new Node(element); // creating node each time with preprder root element;
        int position = findPos(in,n,element); // got position in inordertree
        //mp[element] = INT_MAX;
        
          root->left = constructingTree(pre,preIndex,inStartIndex,position -1,n,in);
          root->right = constructingTree(pre,preIndex,position+1,inEndIndex,n,in);
          return root;
        
    }
    
 
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
          // unordered_map<int,int>mp;
        //   for(int i = 0;i<n;i++)
        //   {
        //       mp[in[i]] = i; // mapping inorder trre node with its index;
        //   }
           
           int preIndex = 0;
           int inStartIndex = 0;
           int inEndIndex = n-1;
           
          Node* ans = constructingTree(pre,preIndex,inStartIndex,inEndIndex,n,in);
          return ans;
           
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends