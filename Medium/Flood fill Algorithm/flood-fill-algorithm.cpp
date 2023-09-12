//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    // USING DFS--------------------------
    
    private:
    void dfs(int row, int col, int initColor, vector<vector<int> >&ans,int delRow[], int delCol[],int newColor)
    {
        // initially mark the start position as new color
        
        ans[row][col] = newColor;
        
        int m = ans.size(); // row size
        int n = ans[0].size(); // col size
        
        // processing the adjacent nodes
        
        for(int i=0;i<4;i++)
        {
            //updation of row and column
            
            int newRow = row + delRow[i];
            int newCol = col +  delCol[i];
            
            // the main condition for checking the neighbour (4 neighbours)
            
            if(newRow >=0 && newRow < m && newCol >= 0 && newCol < n  &&
            ans[newRow][newCol] == initColor && ans[newRow][newCol] != newColor)
            {
                dfs(newRow,newCol,initColor,ans,delRow,delCol,newColor);
            }
        }
        
    }
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
      
        int initColor = image[sr][sc];
        vector<vector<int> >ans = image;
        
        // 4 direction cordinates
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        
        dfs(sr,sc,initColor,ans,delRow,delCol,newColor);
        return ans;
        
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