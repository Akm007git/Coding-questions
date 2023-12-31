//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string temp="";
        string ans ="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == '.')
            {
                //edge case for the last dot of this string
                if(ans.empty())
                {
                    ans = temp+ans;
                    temp="";
                }
                else
                {
                     ans = temp + '.'+ ans;
                     temp="";
                
                }
              
            }
            else
            {
                temp += S[i];
            }
        }
        
        
        
        if(!temp.empty())
        {
            // edge case if string like "HIIIIIIIIIIIIIIII";
            if(ans.empty())
            {
            ans += temp;
            }
            else
            {
               ans = temp + '.' +ans;  // for  last  substring print
            }
            
        }
        
        return ans;
        
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends