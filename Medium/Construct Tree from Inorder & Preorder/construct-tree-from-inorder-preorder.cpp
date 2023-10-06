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
    
    private:
    int findPosition(int in[],int elemnt,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i] == elemnt)
            {
                in[i] = INT_MAX; // if there  duplicate elemnt, no issue 
                return i;
            }
        }
    }
    
    
    private:
    Node* constructionTree(int in[],int pre[],int &preIndex,int inStartIndex,int inEndIndex,int n)
    {
        // base case, if preindex out of the range
        if(preIndex >= n || inStartIndex > inEndIndex)
        {
            return NULL;
        }
        
        int elemnt = pre[preIndex]; // taking the start node from preorder
        
        Node* root = new Node(elemnt);
        
        int position = findPosition(in,elemnt,n); // serching the node in inorder
        
        preIndex++; // for inext irretatio
        
        // travesal left and right part
        //note; for left part range will be  0 --------> pos -1;
        // note: for right part range will be pos+1 -----------> n-1;
        root->left = constructionTree(in,pre,preIndex,inStartIndex,position-1,n);
        root->right = constructionTree(in,pre,preIndex,position+1,inEndIndex,n);
        
        return root;
        
        
        
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preInd = 0;
        int inStartIndex = 0;
        int inEndIndex = n-1;
        return constructionTree(in,pre,preInd,inStartIndex,inEndIndex,n);
   
        
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