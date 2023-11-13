//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
     public:
    //Function to find length of shortest common supersequence of two strings.
    int solver(int i,int j,string x,string y,vector<vector<int>>&dp){
        if(i==x.size())return 0;
        if(j==y.size())return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(x[i]==y[j])ans+=solver(i+1,j+1,x,y,dp)+1;
        else ans+=max(solver(i+1,j,x,y,dp),solver(i,j+1,x,y,dp));
        return dp[i][j]=ans;
        
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
          vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // return n+m-solver(0,0,X,Y,dp);
        // for(int i=0;i<m;i++)
        //      if(X[i]==Y[0])dp[i][0]=1;
        // for(int i=0;i<n;i++)
        //      if(X[0]==Y[i])dp[0][i]=1;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1])dp[i][j]+=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n+m-dp[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends