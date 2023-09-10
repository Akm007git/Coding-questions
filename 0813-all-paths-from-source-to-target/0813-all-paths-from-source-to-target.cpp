class Solution {
public:

void printAll_paths(vector<vector<int>>& graph, vector<vector<int>>&ans, vector<int>path,vector<bool>&visited, int start, int key)
{
    path.push_back(start);
    if(start == key)
    {
        ans.push_back(path);
        return;
    }

    // processing

    for(auto it: graph[start])
    {
        if(!visited[it])
        {
            visited[start] = true;
            printAll_paths(graph,ans,path,visited,it,key);
            visited[start] = false; // while returning
        }
    }
}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        vector<int>path;

        vector<bool>visited(graph.size(),false);

        int start = 0;
        int key = graph.size()-1;

        printAll_paths(graph,ans,path,visited,start,key);
        return ans;


    }
};