//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
      public:
       int delrow[4] = {-1,0,+1,0};
       int delcol[4] = {0,+1,0,-1};
        
    void bfs(int srow, int scol, string &s, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        s.push_back(srow-srow - '0');
        s.push_back(scol-scol - '0');
        
        queue<pair<int,int>>q;
        q.push({srow,scol});
        vis[srow][scol] = 1;
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
                
            for(int i = 0;i < 4;i++){
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];
            
               if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                  vis[nrow][ncol] = 1;
                //   ds.push_back({nrow-srow,ncol-scol});
                  s.push_back(nrow - srow - '0');
                  s.push_back(ncol - scol - '0');
                  q.push({nrow,ncol});
                }
             }
        }
       return;
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
           int n = grid.size();
        int m = grid[0].size();
        
        set<string>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                string str;
               if(grid[i][j] == 1 && !vis[i][j]){
                //   starting row & starting col to store the shape of island
                 bfs(i, j, str, vis, grid);
                 st.insert(str);
               }
            }
            
        }
        
        // for(auto &v: st){
        //     for(auto &it: v){
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends