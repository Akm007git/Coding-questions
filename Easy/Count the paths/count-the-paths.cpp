//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
void dfs(int source, int des, int &count, vector<int> adj[]){
    if(source==des){
        count++;
    }
    for(auto it: adj[source]){
        dfs(it,des,count,adj);
    }
}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
        	    // Code here
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); ++i) {
        int source = edges[i][0];
        int destination = edges[i][1];
        adj[source].push_back(destination);
}

        
        
    int count = 0;
    dfs(s,d,count,adj);
    return count;
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends