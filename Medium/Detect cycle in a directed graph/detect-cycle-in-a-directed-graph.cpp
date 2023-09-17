//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    bool detectCycle(int start,vector<int>adj[],vector<bool>&visited, vector<bool>&recurStack)
    {
        visited[start] = true;
        recurStack[start] = true;
        
        // processing the adjacent nodes
        
        for(auto it: adj[start])
        {
            // when the node is note visited
            if(!visited[it])
            {
                if(detectCycle(it,adj,visited,recurStack) == true) 
                    return true;
            }
            // when the node is visited  previously, and also in present in the recursive stack
            else if(recurStack[it] == true)
            {
                return true;
            }
            
        }
        // back korar somoi, jodi kono adjacent na thake
        recurStack[start] = false;
        return false;
    }
    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool>visited(V,false);
        vector<bool>recurStack(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(i,adj,visited,recurStack) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends