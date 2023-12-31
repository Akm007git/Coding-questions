//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	     vector<vector<int>>dist(n,vector<int>(m,0));
	     vector<vector<int>>visited(n,vector<int>(m,0));
	     
	     queue< pair < pair <int,int>, int > >q;
	     
	     
	     for(int i=0;i<n;i++)
	     {
	         for(int j=0;j<m;j++)
	         {
	             if(grid[i][j] == 1)
	             {
	                 q.push({{i,j},0}); // kepping trave of dist, initially 0
	                 visited[i][j] = 1;
	             }
	         }
	     }
	     // direction part
	     int delRow[] = {0,-1,0,+1};
	     int delCol[] = {-1,0,+1,0};
	     
	     // traverse queueu
	     
	     while(!q.empty())
	     {
	         int row = q.front().first.first;
	         int col = q.front().first.second;
	         
	         int count = q.front().second;
	         
	         q.pop();
	         
	         dist[row][col] = count;
	         
	         for(int i=0;i<4;i++)
	         {
	             int newRow = row + delRow[i];
	             int newCol = col + delCol[i];
	             
	             
	             if(newRow >= 0 &&  newRow < n && newCol >= 0 && newCol < m
	                && visited[newRow][newCol] == 0)
	                {
	                    q.push({{newRow,newCol},count+1});
	                    visited[newRow][newCol] = 1;
	                }
	         }
	         
	         
	         
	     }
	     return dist;
	     
	     
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends