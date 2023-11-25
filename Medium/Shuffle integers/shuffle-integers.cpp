//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int ans[n];
	    int i = 0;
	    int j = n/2;
	    int k = 0;
	    while(i < n/2 && j<n)
	    {
	       
	        ans[k] = arr[i];
	            k++,i++;
	        
	        ans[k] = arr[j];
	            k++,j++;
	        
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i] = ans[i];
	    }
	    
	    return;
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends