//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    void depthFirstSearch(int startNode, vector<int>adj[],vector<int>&ans,vector<bool>&visited)
    {
        
        visited[startNode] =  true; // starting node mark true
        ans.push_back(startNode);
        
        // processsing the other adjucent neighbouring node
        
        for(auto it: adj[startNode]) // each adj[startnode is a vector of corrospondinng neighbour node]
        {
            if(visited[it] == false)
            {
                depthFirstSearch(it,adj,ans,visited);
            }
        }
            
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false); // for tracking , node is visited or not
        
        int startElemnt = 0;
        vector<int>dfs; // for storing the elemnt
        depthFirstSearch(startElemnt,adj,dfs,visited);
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