//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row,int col,vector<vector<bool>>&visited,vector<vector<char>>&grid ,int m, int n)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
         visited[row][col] = true;
         
         while(!q.empty())
         {
             int row = q.front().first;
             int col = q.front().second;
             q.pop();
             
             // traversing adjacnt node
             
                 // i have to chck all the 8 sides
                 for(int i=-1;i<=1;i++)
                 {
                     for(int j=-1;j<=1;j++)
                     {
                         int newRow = row + i;
                         int newCol = col + j;
                         
                         // chclking these condition
                         
                         if(newRow >=0 && newRow < m && newCol >= 0 && newCol < n 
                         && visited[newRow][newCol] == false && grid[newRow][newCol] == '1')
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
        int m = grid.size(); //row
        int n  = grid[0].size(); // col
        
        //
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        int count = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(i,j,visited,grid,m,n);
                    count++;
                }
            }
        }
        
        return count;
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