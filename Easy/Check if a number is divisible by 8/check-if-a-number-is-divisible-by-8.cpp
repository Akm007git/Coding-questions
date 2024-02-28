//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.size() <= 3)
        {
            int num = stoi(s);
            
            if(num % 8 == 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
           string str = s.substr(s.size() - 3);
            int num2 = stoi(str);
            
            if(num2 % 8 == 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
            
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends