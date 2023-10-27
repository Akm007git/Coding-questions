//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int solve(string& S, string&rev, int i, int j, vector<vector<int>>&dp) {
      if(i==S.length() || j==rev.length()) {
          return 0;
      }
      int ans = 0;
      if(dp[i][j]!=-1) return dp[i][j];
      if(S[i]==rev[j]){
          ans = 1 + solve(S,rev,i+1,j+1,dp);
      }
      else {
          ans = max(solve(S,rev,i+1,j,dp),solve(S,rev,i,j+1,dp));
      }
      return dp[i][j] = ans;
  }
  
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        vector<vector<int>>dp(S.length(),vector<int>(S.length(),-1));
        string rev = S;
        reverse(rev.begin(),rev.end());
        int result = solve(S,rev,0,0,dp);
        return S.length() - result;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends