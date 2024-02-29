//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    private:
    void dfs(int start,vector<int>adj[],vector<bool>&visited)
    {
        visited[start] = true ;
        
        // processing other nodes'
        
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjlist[V];
        
        // matrix to listv conv
        for(int i = 0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                    
                }
            }
        }
        
        vector<bool>visited(V,false);
        
        int count  = 0;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adjlist,visited);
                count++;
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