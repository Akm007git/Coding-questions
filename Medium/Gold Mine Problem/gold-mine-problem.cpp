//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& arr, int n, int m,vector<vector<int>>&dp) {
        // base case
        if (r < 0 || c < 0 || r >= n || c >= m) {
            return 0;
        }
        
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int currentGold = arr[r][c];
        int dUpRight = solve(r - 1, c + 1, arr, n, m,dp);
        int dDownRight = solve(r + 1, c + 1, arr, n, m,dp);
        int right = solve(r, c+1 , arr, n, m,dp);

        dp[r][c] = currentGold + max(dUpRight, max(dDownRight, right));
        return dp[r][c];
    }

    int maxGold(int n, int m, vector<vector<int>> M) {
        // finding the max value from the first column
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
           int val =  solve(i, 0, M, n, m, dp);
           ans = max(val, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends