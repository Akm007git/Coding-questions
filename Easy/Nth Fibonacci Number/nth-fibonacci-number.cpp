//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod = 1e9+7;
 private:
 
 int nthTerm(vector<int>&dp, int n)
 {
     if(n <= 1)
        return n;
     
     if(dp[n] != -1)
        return dp[n];
    
    dp[n] = ( nthTerm(dp,n-1)%mod+ nthTerm(dp,n-2)%mod )%mod;
    return dp[n];
 }
  public:
    int nthFibonacci(int n){
        // code here
       vector<int>dp(n+1,-1);
       return nthTerm(dp,n);
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