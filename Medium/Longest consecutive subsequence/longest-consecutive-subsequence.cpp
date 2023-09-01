//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int N)
    {
      //Your code here
      sort(a,a+N);
    int count =1; //for single element count and the length will be always 1
    int length =1;
    for(int i=0;i<N-1;i++)
    {
        int diff = a[i+1] - a[i];
        if(diff == 1)
        {
            count ++;
        }
        else if(diff == 0) // elements are equal
        {
            continue;
        }
        else{ // if greater than diff, then put the count into base whivh is 1 1
            count = 1;
        }

        length = max(count,length);
    }
    return length;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends