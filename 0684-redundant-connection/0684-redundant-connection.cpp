class Graph
{
    public:
    vector<int>parent;
    vector<int>rank;

    Graph(int size)
    {
        parent.resize(size+1);
        rank.resize(size+1,0);

        for(int i=0;i<size;i++)
        {
            parent[i] = i; // initilalize with itself
        }
    }

    // check ultimate parent
    int findUltimateParent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
      return parent[node] = findUltimateParent(parent[node]);

        
    }
    // rank

     void unionByRank(int u,int v, vector<int>&ans)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu == pv)
        {
            ans = {u, v};
            return;
        }
        else
        {
            if(rank[pu] == rank[pv])
            {
                parent[pv] = pu;
                rank[pu]++;
            }
            else if(rank[pu] > rank[pv])
            {
                parent[pv] = pu;
                rank[pu]++;
            }
            else
            {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }

};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int>ans;
        int n = edges.size();
        Graph ds(n);

       for(auto it: edges)
       {
           int u = it[0];
           int v = it[1];

        ds.unionByRank(u, v, ans);
       }

       return ans;
  
    }
};