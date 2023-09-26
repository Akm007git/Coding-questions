//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int start, vector<bool>&visited,stack<int>&st, vector<vector<int>>&adj)
    {
        visited[start] = true;
        
        // proesiing adj nodes
        for(auto it: adj[start])
        {
            if(!visited[it])
            {
                dfs(it,visited,st,adj);
            }
        }
        st.push(start);
    }
    
    private:
    void finalDfs(int start, vector<bool>&visited,vector<int>Tradj[])
    {
        visited[start] = true;
        
        // processingadj nodes
        for(auto it: Tradj[start])
        {
            if(!visited[it])
            {
                finalDfs(it,visited,Tradj);
            }
        }
            
    }
    
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool>visited(V,false);
        stack<int>st;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                 dfs(i,visited,st,adj);
            }
        }
        
        // sort by finishing time  done
        
    // step:2 forreverse the graph
    
     vector<int>Tradj[V];
     
    
    // make reverse graph
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        
        for(auto it: adj[i])
        {
            Tradj[it].push_back(i);  //reversely connected;
        }
    }
    
    // then traverse through dfs and thenode comming from the stack
    int src = 0;
    
    while( !st.empty())
    {
        int node = st.top();
        st.pop();
        
        if(!visited[node])
        {
            src++;
            finalDfs(node,visited, Tradj);
        }
    }
     
     return src;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends