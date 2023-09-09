//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false); // for checking visited or not
        queue<int>q;
        
        // initially, push the first element and mark visited
        q.push(0);
        visited[0] = true;
        vector<int>bfs;
        while( !q.empty())
        {
            int node = q.front();
            q.pop();
            
            // store the element
            bfs.push_back(node);
            // processing  adjucent nodes
            
            for(auto it:adj[node]) // here adj[node] representing corospondibng vector, ans it is all elemnt of that vector
            {
                if( visited[it] == false)
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
            
        }
        return bfs;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends