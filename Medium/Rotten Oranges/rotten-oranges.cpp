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
        
        // creating a 2d visited array
        
       // int visited[n][m] = {0};
        
        // also  i can srite this 
        vector<vector<int> >visited(n, vector<int>(m,0));
        
        // pair with postion also timer
        
        queue<pair<pair<int,int>,int > >q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                
            }
        }
        
        // inititially q push done
        
        int totalTime = 0;
        
        // for traverse all 4th direction
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while( !q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time  = q.front().second;
            q.pop();
            
            //store the time each time
            totalTime = time;
            
            // all neighbour processing  done 
            for(int i = 0;i<4;i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >= 0 && newRow <n && newCol >= 0 && newCol<m &&
                visited[newRow][newCol] == 0  && grid[newRow][newCol] == 1 )
                {
                    q.push({{newRow, newCol},time+1});
                    visited[newRow][newCol] = 2;
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
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