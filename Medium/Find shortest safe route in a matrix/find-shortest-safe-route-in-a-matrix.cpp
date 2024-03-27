//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int f(int x,vector<vector<int>> &mat){
   
     int n=mat.size();
       int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    q.push({x,0});
    int count=0;
       while(q.size()!=0){
           count++;
           int n1=q.size();
           for(int i=0;i<n1;i++){
           int a=q.front().first;
           int b=q.front().second;
           q.pop();
           if(b==m-1){
               return count;
           }
             if(a+1<n && mat[a+1][b]==1 && vis[a+1][b]==0){
                 q.push({a+1,b});
                 vis[a+1][b]=1;
             } 
             if(a-1>=0 && mat[a-1][b]==1&& vis[a-1][b]==0){
                 vis[a-1][b]=1;
                  q.push({a-1,b});
             }
             if(b+1<m && mat[a][b+1]==1&& vis[a][b+1]==0){
                 vis[a][b+1]=1;
                  q.push({a,b+1});
             }
             if(b-1>=0 && mat[a][b-1]==1&& vis[a][b-1]==0){
                  q.push({a,b-1});
                  vis[a][b-1]==1;
             }
               
           }
       }
       
       return 1e8;
}
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int n=mat.size();
       int m=mat[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]==0){
                   if(j-1>=0){
                         mat[i][j-1]=-1;  
                       }
                   if(j+1<m){
                         mat[i][j+1]=-1;  
                       }
                   if(i+1<n){
                       mat[i+1][j]=-1;
                   }
                   if(i-1>=0){
                       mat[i-1][j]=-1;
                       
                   }
               }
           }
           
           
       }
       
    //   vector<vector<int>> dist(n,vector<int>(m,1e8));
       
       int mini =1e8;
       for(int i=0;i<n;i++){
           if(mat[i][0]==1){
           mini=min(mini,f(i,mat));
               
           }
       }
       
       if(mini==1e8) return -1;
       else return mini ;
       
       
       
       
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends