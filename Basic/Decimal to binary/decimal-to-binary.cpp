//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here'
    string ans = "";
    
    while(N)
    {
        int rem = N%2;
        char ch = rem+'0';
        ans+=ch;
        N/=2;
    }
    
    reverse(ans.begin(), ans.end());
    cout<<ans;
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends