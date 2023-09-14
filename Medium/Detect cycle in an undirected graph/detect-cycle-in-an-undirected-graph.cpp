//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
    /* USING BFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/
    
    private:
    
    bool bfs(int start, vector<int>adj[], vector<bool>&visited)
    {
        visited[start] = true;
        
        queue<pair<int,int> >q; // node, and its parent
        
        q.push(make_pair(start,-1)); // initially parent is -1;
        
        while( !q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            // processing the adjacent nodes
            for(auto adjNodes : adj[node])
            {
                if(visited[adjNodes] == false)
                {
                    q.push({adjNodes,node}); // here node is the parent of adjacent nodes
                    visited[adjNodes] = true;
                    
                }
                
                else if(adjNodes != parent) // jodi adjacent visit thake, check korte hobe ota patent ki nna? if parent then ok  nato cycle
                {
                    return true;
                }
                
                
                /*  else // jodi adjacent visit thake, check korte hobe ota patent ki nna? if parent then ok  nato cycle
                {
                    if(adjNodes != parent) 
                        return true;
                } */
            }
        }
        
        return false;
        
    }
    
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>visited(V,false);

        
        // for different componenets
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,adj,visited))
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