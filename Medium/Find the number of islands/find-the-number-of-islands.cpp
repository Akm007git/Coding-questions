//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void solveByDfs(int row, int col , vector<vector<bool>>&visited, vector<vector<char>>grid )
  {
        int n =grid.size();
        int m = grid[0].size();
        
      visited[row][col] = true;
      int drow = row;
      int dcol = col;
      
      // traversing all 8 direction
      for(drow = -1; drow <= 1;drow++)
      {
          for( dcol = -1; dcol <= 1;dcol++)
          {
              int newRow = row +drow;
              int newCol = col + dcol;
              
              
              if(newRow >=0 &&  newRow <n  && newCol >= 0 && newCol <m 
                    && !visited[newRow][newCol] && grid[newRow][newCol] == '1' )
              {
                  
                  solveByDfs(newRow,newCol,visited,grid);
              }
          }
      }
  }
  
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n =grid.size();
        int m = grid[0].size();
        
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    
    int iSland = 0;
    
    
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++ )
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    solveByDfs(i,j,visited,grid);
                    iSland++;
                }
            }
        }
    
    return iSland++;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends