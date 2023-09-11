//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
    private:
    void  bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited )
    {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q ;
        
        // initially oush the start node
        q.push({row,col});
        
        // mark as true of initial node
        visited[row][col] = true;
        
        while( !q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // now traversing and checking all thw adjacent nodes
            
            for(int delRow = -1;delRow<=1;delRow++)
            {
                for(int delCol = -1 ;delCol <=1; delCol++)
                {
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    
                    // checking visited or not, each neighbour
                    if( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                        grid[newRow][newCol] == '1' && !visited[newRow][newCol] )
                     {
                         visited[newRow][newCol] = true;
                         q.push({newRow,newCol});
                     }
                    
                }
            }
        }
        
        
        
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n  = grid.size();
        int m = grid[0].size();
        int island = 0;
        
        
        vector<vector<bool> >visited(n,vector<bool>(m,false)); // vector of vector with all false
        for(int row = 0; row<n;row++)
        {
            for(int col = 0; col<m;col++)
            {
                if( !visited[row][col] && grid[row][col] == '1' )
                {
                    island ++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        return island;
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