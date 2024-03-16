//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        // i ve to take track of  the time simmultaneouslt, with the row and col
        //queue<pair<pair<int,int>,int>>q;
        
        queue<pair< pair<int,int>,int> >q; 
          int totalTime  = 0;
        
        
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 2 &&  !visited[i][j])
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }
        
      
        
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,+1,0};
        
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            totalTime = time;
            
            // travevrsing all the sides
            for(int i=0;i<4;i++)
            {
                int newRow  = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n
                && grid[newRow][newCol] == 1 && visited[newRow][newCol] !=2)
                {
                    q.push({{newRow,newCol},time+1});
                    visited[newRow][newCol] = 2;
                }
            }
        }
            
            // all set for the visited array
            // finalmcheck
            
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(grid[i][j] == 1 && visited[i][j] != 2)
                    {
                        return -1;
                    }
                    
                }
            }
            return totalTime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends