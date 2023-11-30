//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(int start, vector<int>adj[], vector<bool>&visited)
    {
        
        visited[start] = true; // initially start marked as true;
        queue< pair <int,int > >q;
        
        q.push(make_pair(start,-1)); // initially parent is passing as -1
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto it: adj[node])
            {
                if(!visited[it]){ // if the adj nodes (it) not visited, pusg in queue, and visit
                    q.push({it,node}); // that case parent will node, & "it" is adj nodes
                    visited[it] = true;
                }
                else if( it != parent ){ // menas, adj node visited and also not parent, means cycle must
                    return true;
                }
            }
        }
        // if any case doesnt follow, means,no cycle
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    
    // USING BFS----------------
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,adj,visited)){
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