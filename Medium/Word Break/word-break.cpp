//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
          int l=s.length();
        vector<int>dp(l+1,0);
        dp[0]=1;
        for(int i=0;i<=l;i++)
        {
            for(string& word:dictionary){
                int start=i-word.length();
                if (start >= 0 && dp[start] == 1 && s.substr(start, word.length()) == word) {
                dp[i] = 1;
                break;
                }
            }
        }
        return dp[l];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends