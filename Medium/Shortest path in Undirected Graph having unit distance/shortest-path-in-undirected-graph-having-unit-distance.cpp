//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // ccreate an adjacency list
        vector<int>adj[N];
        for(auto edge :edges )
        {
            int u = edge[0];
            int v = edge[1];
            
            //as undirecetd graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // initially mark as int_max
        
        vector<int>dist(N);
        for(int i=0;i<N;i++)
        {
            dist[i] = 1e9;
        }
        dist[src] = 0; // as initially 0 to 0 distence will be zero
        
        queue<int>q;
        q.push(src); // push thhe initial node
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int wt = 1; // each time wt will be one
            
            // processing the neighbour nodes
            for(auto it:adj[node]) // here it are the all element of corrosponding vector
            {
                if(dist[node]+wt < dist[it])
                {
                    dist[it] = dist[node]+wt;
                    q.push(it);
                }
            }
        }
        
        // if there any intmax mark as -1;
        vector<int>ans(N,-1);
       for(int i=0;i<N;i++)
       {
           if(dist[i] != 1e9)
            ans[i] = dist[i];
       }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends