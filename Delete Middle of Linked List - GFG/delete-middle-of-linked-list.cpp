//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    
      if (head->next == NULL)
            return NULL;
    
        Node* temp = head;
        int count =0;
        
        // calculating the length
        
        while(temp != NULL)
        {
            count ++;
            temp=temp->next;
        }
        
       // finding mid element delete and cinnect
       
        temp = head;
        int c =1;
        while(c < count/2 && temp != NULL)
        {
            temp = temp->next;
            c++;
        }
        
        // delete and connect the link
        
        Node* next = temp->next->next;
        Node* del = temp->next;
        temp->next = next;
        del->next = NULL;
        return head;
        
        
        
        
       
     
     
}