//{ Driver Code Starts
//Initial template for C++

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
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    private:
    Node* reverseList(Node* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        Node* previous = NULL;
        Node* current = head;
        
        while(current != NULL)
        {
            Node* forward = current->next;
            current->next = previous;
            
            // updation
            previous = current;
            current = forward;
        }
        return previous;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        //STEP 1 REVERSE THE LIST, AS ADD WITH LAST ITEM
         head = reverseList(head);
         
         Node* current = head;
         while(current != NULL)
         {
             //CASE 1, LAST ELEMNT , WITH 9 VALUE
             if(current->next == NULL && current->data == 9)
             {
                 current->data = 1;
                 Node* temp = new Node(0); // extra 0 add to the first, aftrer reverse finally add 0 at last
                 temp->next = head;
                 head = temp;
                 current = current->next;
             }
             else if(current->data == 9)  // CASE 2:ONLY ONE 9
             {
                 current->data = 0;
                 current = current->next;
                 
             }
             else if(current->data != 9) // case 3: last elemnt not 9
             {
                 current->data += 1;
                 break;
             }
             
         }
         
         head = reverseList(head); // got the previous state
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends