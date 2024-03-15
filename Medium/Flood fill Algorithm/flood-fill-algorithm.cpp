//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    void bfs(int row,int col,int initColor,vector<vector<int>>&adj,int m,int n,int newColor)
    {
        // mark true first position
        
        queue<pair<int,int>>q;
        q.push({row,col});
        
        adj[row][col] = newColor; //2  initially mark with new color
        
        //we need to traverse 4 directions, lets get a map the whole dirctions  
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // traversing 4 sidew
            for(int i=0;i<4;i++)
            {
                int newRow = row + delRow[i];
                int newCol =  col + delCol[i];
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                adj[newRow][newCol] == initColor && adj[newRow][newCol] !=  newColor)
                {
                    q.push({newRow,newCol});
                    adj[newRow][newCol] = newColor;
                }
            }
        }
        
    }
public: 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int m = image.size();
        int n = image[0].size();
         int initColor = image[sr][sc];
        
        vector<vector<int>>adj = image;
        
        
        bfs(sr,sc,initColor,adj,m,n,newColor);
        return adj;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends