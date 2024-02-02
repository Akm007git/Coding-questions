//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0;
        int ans =0;
        bool flag;
        if(str[i] == '-')
        {
            flag = true;
        }
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '-' && i >1)
                return -1;
        }
            
        while(i<str.size())
        {
            if(str[i] >= 'a' && str[i] <= 'z'  )
            {
                return -1;
            }
            else if(str[i] == '-')
            {
                
                if(str[i+1] == '-' || str[i+1] == '+' )
                {
                    return -1;
                }
                
                i++;
                continue;
            }
           
            else 
            {
                int digit = str[i]-'0';
                  ans = ans *10+digit;
            }
            
            i++;
        }
        if (flag) return ans * (-1);
        else return ans;
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
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends