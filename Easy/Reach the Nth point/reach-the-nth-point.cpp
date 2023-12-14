//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9+7;
    private:
    int count(int n,vector<int>&dp){
        if(n <=1){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int c1 = count(n-1,dp);
        int c2 = count(n-2,dp);
        
        dp[n] = (c1+c2)%mod;
        return dp[n];
    }
    
	public:
		int nthPoint(int n){
            
        vector<int>dp(n+1,-1);
        return count(n,dp);
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends