class Solution {
public:

int finalCost(vector<int>cost,int n,vector<int>&dp)
{
    // basecase
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    
    if(dp[n] != -1)
        return dp[n];
        

    //recursive call
     dp[n] = cost[n] + min( finalCost(cost,n-1,dp),finalCost(cost,n-2,dp) );
        return dp[n];
    
}

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        int ans = min ( finalCost(cost,n-1,dp), finalCost(cost,n-2,dp) );
        return ans;
        
    }
};