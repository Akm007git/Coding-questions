//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    void bfs(int sr,int sc,vector<vector<int>>&ans,int initColor,int newColor,int delRow[],int delCol[],int m,int n)
    {
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        ans[sr][sc] = newColor;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
             for(int i=0;i<4;i++)
             {
               
                int newRow = row + delRow[i]; // update the row and column ,according to 4 direction
                int newCol = col +delCol[i];
                
                // recursive call
                // condition, first of all check in range or not
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && ans[newRow][newCol] == initColor && ans[newRow][newCol]  != newColor)
                {
                    ans[newRow][newCol] = newColor;
                    q.push({newRow,newCol});
                }
             }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initColor = image[sr][sc];
        
        vector<vector<int>>ans = image;
        
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        int n = image.size();// row size
        int m = image[0].size();// col size
        
        bfs( sr,sc,ans,initColor,newColor,delRow,delCol,m,n); // here new color = 2;we have to update all case in 2, if possible
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