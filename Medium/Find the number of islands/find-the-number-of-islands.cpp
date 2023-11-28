//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row,int col,vector<vector<bool>>&visited,vector<vector<char>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({row,col}); // initially pysh the appropriate elemnt
        visited[row][col] = true; //marl them as true;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // we have to traverse all 8 way to check ythe sland or not
            for(int delRow = -1;delRow <= 1 ;delRow++) // range will be -1 to 1 
            {
                for(int delCol = -1;delCol <= 1;delCol++) // same range
                {
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    
                    // checkng all the combinations
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                            !visited[newRow][newCol] && grid[newRow][newCol] == '1' )
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
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        // traverse
        for(int i=0;i<n;i++) // traverse row wise
        {
            for(int j=0;j<m;j++) // traverse column wise
            {
                if(!visited[i][j] && grid[i][j] == '1') // comapreing that cell with '1' charecyer
                {
                    bfs(i,j,visited,grid);
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