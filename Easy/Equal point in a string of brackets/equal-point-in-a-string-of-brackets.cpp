//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int findIndex(string str) {
        // Your code goes here   
        
        
        
        // edge case
        if(str.size() == 1 && str[0] == '(')
        {
            return 0;
        }
        // count the total closing bra
        int closeB = 0;
        
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == ')')
            {
                closeB++;
            }
        }
        
        // trverse and check
        int openB = 0;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '(')
            {
                openB++;
            }
            else
            {
                closeB--;
            }
            
            if(openB == closeB)
            {
                return i+1;
            }
        }
        return -1;
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
		Solution ob;
		cout<<ob.findIndex(s)<<endl;
	}
}
// } Driver Code Ends