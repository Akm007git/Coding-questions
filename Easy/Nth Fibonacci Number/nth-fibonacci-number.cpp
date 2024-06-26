//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod = 1e9+7;
    private:
    int fibbo(int n, vector<int>&dp)
    {
        if(n <= 1)
        {
            return n;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
         dp[n] = ( fibbo(n-1,dp)%mod + fibbo(n-2,dp)%mod )%mod;
         return dp[n];
    }
  public:
    int nthFibonacci(int n){
        // code 
        
        vector<int>dp(n+1,-1);
        
        return fibbo(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends