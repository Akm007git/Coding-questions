//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
  Node* getMid(Node* &head)
  {
       //Your code here
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
  }
  
  Node* getReverse(Node* &head)
  {
      Node* previous = NULL;
      Node* current = head;
      
      while(current != NULL)
      {
          Node* forward = current->next;
          current->next = previous;
          
          previous = current;
          current = forward;
      }
      return previous;
  }
  
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       
       if(head->next == NULL)
            return 1;

        
        Node* middle = getMid(head); // function calling
       

        Node* reverseHead = getReverse(middle->next); // function calling
        //cout<<reverseHead->data <<endl;
        
        Node* head1 = head;
        Node* head2 = reverseHead;
        while(head1 && head2)
        {
            if(head1->data == head2->data )
            {
                head1 = head1->next;
                head2 = head2->next;
                
            }
            else
            {
                return false;;
            }
        }
        return true;
        
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends