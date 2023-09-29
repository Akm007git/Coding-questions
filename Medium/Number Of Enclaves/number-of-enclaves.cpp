//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    int help(vector<vector<int>> &grid, int row, int col, int i, int j, vector<vector<int>> &vis)
    {
        if( (i>=row || j>=col || i<0 || j<0) || grid[i][j] == 0) return 0;
        
        if(grid[i][j] == 1 && vis[i][j] == 0)
        {
            vis[i][j] = 1;
            
            int count = 1;
        
            count += help(grid, row, col, i-1, j, vis);
            count += help(grid, row, col, i, j+1, vis);
            count += help(grid, row, col, i+1, j, vis);
            count += help(grid, row, col, i, j-1, vis);
            
            return count;
        }

    }
    public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int row = grid.size();
        int col = grid[0].size();
        
        int land = 0;
        
        vector<vector<int>> vis(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++) 
                if(grid[i][j] == 1) land++;
        
        int count = 0;
        for(int i=0; i<row; i++)
        {
            if(grid[i][0] == 1) count += help(grid, row, col, i, 0, vis);
            if(grid[i][col-1] == 1) count += help(grid, row, col, i, col-1, vis);
        }
        for(int i=1; i<col-1; i++)
        {
            if(grid[0][i] == 1) count += help(grid, row, col, 0, i, vis);
            if(grid[row-1][i] == 1) count += help(grid, row, col, row-1, i, vis);
        }
        return land-count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends