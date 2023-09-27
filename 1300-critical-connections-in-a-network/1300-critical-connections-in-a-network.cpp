class Solution {

private:
void solveBydfs(int node, int parent,int &timing, 
vector<int>&ins,vector<int>&low, vector<bool>&visited,vector<int>adj[],vector<vector<int>>&bridges)
{

    visited[node] = true;
    ins[node] = low[node] = timing;

    timing++;

    // procesiing adj nodes

    for(auto it:adj[node])
    {
        // if adj nodes is parent
        if(it == parent )
        {
            continue;
        }

        if(!visited[it])
        {
            solveBydfs(it,node,timing,ins,low,visited,adj,bridges);

            low[node] = min(low[it],low[node]);
            // bridge check
            if(ins[node] < low[it])
            {
                bridges.push_back({node,it}); 
            }
        }
        else
        {
            low[node] = min(low[it],low[node]);
        }
    }

}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // creating undirected adjacentnodes
        vector<int>adj[n];
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>insTime(n);
        vector<int>lowInsTime(n);


        vector<vector<int>>bridges;
        vector<bool>visited(n,false);
        int timing = 1;
        int src = 0;
        int parent = -1;
        solveBydfs(src,parent,timing,insTime,lowInsTime,visited,adj,bridges);
        return bridges;
        

    }
};