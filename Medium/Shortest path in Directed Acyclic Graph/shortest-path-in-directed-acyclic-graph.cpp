//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    private:
    
    void topologicalSort(int start, vector<pair<int,int> >adj[], int visited[], stack<int>&st)
    {
        visited[start] = 1;
        
        // processing adj nodes
        
        for(auto it:adj[start])
        {
           int v = it.first;
            if(!visited[v])
            {
                topologicalSort(v,adj,visited,st);
            }
        }
        
        st.push(start);
    }
    
    
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int> >adj[N];
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            // create an adjacency list
            adj[u].push_back({v,wt});
        }
        
        // step:1 topological sort done
        
        int visited[N] = {0};
        stack<int>st;
        
        for(int i=0;i<N;i++)
        {
            if(!visited[i] )
            {
                topologicalSort(i,adj,visited,st);
            }
        }
        
        // processing and checking eith the dist
        vector<int>dist(N);
        for(int i=0;i<N;i++)
        {
            dist[i] = 1e9;
        }
        
        
            dist[0] = 0 ;
            
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                
                for(auto it: adj[node]) // its basically a pair, of, distence and distence
                {
                    int v = it.first;
                    int wt =  it.second;
                    
                    // main condition for checkung shortest text
                    if(dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node]+wt;
                    }
                    
                }
            }
                
                  for(int i=0; i<N; i++)
                  {
                       if(dist[i]==1e9)
                            dist[i]=-1;
                  }
                       
            
            return dist;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends