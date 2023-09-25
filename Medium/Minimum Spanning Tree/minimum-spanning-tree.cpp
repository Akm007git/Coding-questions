//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vc vector<int>

class disjoint
{
public:
    vc parent, rank, Size; // initialize two vector

    disjoint(int size)
    {
        rank.resize(size + 1, 0); // intialize with 0
        parent.resize(size + 1);
        Size.resize(size + 1, 1);
        // parent vector initialie with ultimate parent , means itself
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }

    // find ultimate parent and also path cmpression

    int findUltimateParent(int node)
    {
        if (parent[node] == node) // parent is itself
            return node;
        else
        {
            // using dp, memorise the parent directly with each node, path compression
            parent[node] = findUltimateParent(parent[node]);
            return parent[node];
        }
    }

    // by rank
    void unionByRank(int u, int v)
    {
        int ultimateParent_U = findUltimateParent(u);
        int ultimateParent_V = findUltimateParent(v);

        // step1 , check both ultimate parent equal or not
        if (ultimateParent_U == ultimateParent_V) // node in same componenet
        {
            return;
        }
        else if (rank[ultimateParent_U] < rank[ultimateParent_V])
        {
            parent[ultimateParent_U] = ultimateParent_V;
            rank[ultimateParent_V]++;
        }
        else if (rank[ultimateParent_V] < rank[ultimateParent_U])
        {

            parent[ultimateParent_V] = ultimateParent_U;
            rank[ultimateParent_U]++;
        }
        else
        {

            parent[ultimateParent_U] = ultimateParent_V;
            rank[ultimateParent_V]++;
        }
    }
};


/*--------------MAIN CLASS -------------------*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int,int> > > edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjnode}}); // adding i adges
            }
        }
        
        sort(edges.begin(),edges.end()); // sort for minimum size
        disjoint ds(V);
        
        int sum = 0;
        
        for(auto it:edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltimateParent(u) !=  ds.findUltimateParent(v))
            {
                sum += wt;
                ds.unionByRank(u,v);
            }
            
            
        }
        return sum;
        
        
        
        

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends