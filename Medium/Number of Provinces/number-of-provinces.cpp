//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    private:
    
    void dfs(int start, vector<bool>&visited,vector<int>adjlist[])
    {
        
        visited[start] = true;
        
        for(auto it: adjlist[start])
        {
            if(!visited[it])
            {
                dfs(it,visited,adjlist);
            }
        }
    }
    
    
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        // creating adjacency list from matrix
        vector<int>adjlist[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1 && i != j )
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        // using adjacency list
        
        int count = 0;
        vector<bool>visited(V,false);
        
        for(int i = 0;i<V;i++)
        {
            if(visited[i] == false)
            {
                count++;
                dfs(i,visited,adjlist);
                
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends