//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node*rev(Node*head){
        Node*curr=head;
        Node*forward=NULL;
        Node*prev=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *head1,Node *head2)
    {
        // your code goes here
        head1=rev(head1);
       head2=rev(head2);
       Node*temp=new Node;
       Node*trk=temp;
       
       while(head1!=NULL && head2!=NULL){
            if(head1->data > head2->data){
                temp->next=head1;
                head1=head1->next;
                temp=temp->next;
            }
            else{
                temp->next=head2;
                head2=head2->next;
                temp=temp->next;
            }
        }
        
        while(head1!=NULL){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        
        while(head2!=NULL){
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
        
        trk=trk->next;
        return trk;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends