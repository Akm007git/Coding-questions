//{ Driver Code Starts
//

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


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
        
        // If list is empty or new node should be inserted at the beginning
        if (head == NULL || data < head->data) {
            newNode->next = head;
            return newNode; // new node becomes the new head
        }
        
        Node* previous = head;
        Node* current = head->next;
        
        while (current != NULL) {
            if (data <= current->data) {
                previous->next = newNode;
                newNode->next = current;
                return head; // insertion completed, return the original head
            }
            
            previous = current;
            current = current->next;
        }
        
        // If data is larger than all existing elements, insert at the end
        previous->next = newNode;
        return head;
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
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends