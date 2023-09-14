//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    bool detectCycleBYDFS(int node, int parent, vector<int>adj[], vector<int>&visited)
    {
        visited[node] = 1;
        
        for(auto adjNodes : adj[node]) // heree node is parent, and adjnodes is child
        {
            if(!visited[adjNodes])
            {
                if(detectCycleBYDFS(adjNodes,node,adj,visited) == true) // if some wgere in the rocess of recursion we got already visited or true
                {
                    return true;
                }
            }
            else // it means adjacent node alredy visited
            {
                if(adjNodes != parent) // if adjacent  is not the parent node
                    return true;
            }
        }
        return false;
    }
    
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        int start = 0;
        int parent = -1;
        
        // for all components
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycleBYDFS(i, parent,adj,visited))
                    return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends