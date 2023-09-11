class Solution {
public:

 void dfs(int start, vector<bool>&visited,vector<int>adj[])
    {
        
        visited[start] = true;
        
        for(auto it: adj[start])
        {
            if(!visited[it])
            {
                dfs(it,visited,adj);
            }
        }
    }
    

    int findCircleNum(vector<vector<int>>& isConnected) {

         int n = isConnected.size() ;
         vector<int>adj[n];

         // creating adjlistf from matrix
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(isConnected[i][j] == 1 && i != j)
                 {
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                 }
             }
         }

        // using adjacency list

         int count = 0;
        
        vector<bool>visited(n,false);
        
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == false)
            {
                count++;
                dfs(i,visited,adj);
                
            }
        }
        return count;
    }
};