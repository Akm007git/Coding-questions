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
        
        int n = grid.size();
        int m = grid[0].size();
        
        // taking same size visited array
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        // push all the rotten element in queueu , also keep track of timing
        
        queue<pair<pair<int,int>,int>>q;
        int timing = 0;
        
        
        for(int i=0;i<n;i++) // traverse  row wise 
        {
            for(int j=0;j<m;j++)  // traverse col wise
            {
                if(grid[i][j] == 2 && !visited[i][j]){
                    q.push({{i,j},0});
                    visited[i][j] = 2; // marking the visited array
                }
                    
            }
        }
        
        // handeling the direction
       int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        // traverse the queueu
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curr_time = q.front().second;
            
            q.pop();
            
            // saving the time after onr total iration of all direction
            timing = curr_time;
            
            for(int i = 0;i<4;i++)
            {
                int nR = row + delRow[i];
                int nC = col + delCol[i];
                
                if( nR >= 0 && nR < n &&  nC >= 0 && nC < m 
                    && grid[nR][nC] == 1  && visited[nR][nC] != 2) // if new cell er value 1 hoi, means not rottenn hoi and, non visited hoi
                    {
                        
                        q.push({{nR,nC},curr_time+1}); // time increase , after a full iteration
                        visited[nR][nC] = 2;
                    }
                
            }
        }
        
        // queue traversa done
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && visited[i][j] != 2) //means, somewhre not all egg rotten
                    return -1;
            }
        }
        
        return timing;
        
        
        
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