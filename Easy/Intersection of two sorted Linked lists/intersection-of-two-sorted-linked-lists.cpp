//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node* dummy = new Node(-1);
        Node* dummyTemp = dummy;
        Node* temp = head1;
        Node* temp2 = head2;
        
        while(temp && temp2)
        {
            if(temp->data < temp2->data)
            {
                temp = temp->next;
            }
            else if(temp->data > temp2->data)
            {
                temp2 = temp2->next;
            }
            else
            {
               
               Node* current = new Node(temp->data); // making node using this data
               dummyTemp->next =current; // connecting nodes dummy---current
               dummyTemp = dummyTemp->next;  // updating dummy one step
                
                //updation of main poointer
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
          dummy = dummy->next; // as -1 is dummy after that all the data is connected
        
        return  dummy;
        
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends