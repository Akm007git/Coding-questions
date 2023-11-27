//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void depthSearch(int node,vector<bool>&visited,vector<int>&dfs,vector<int>adj[])
    {
        visited[node] = 1; // initially marked as one;
        dfs.push_back(node); // push the eleemnt
        
        // process the other part
        
        for(auto it: adj[node])
        {
            if(visited[it] == 0)
            {
                depthSearch(it,visited,dfs,adj);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,0);
        
        vector<int>dfs;
        
        int start = 0;
        
        depthSearch(start,visited,dfs,adj);
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends