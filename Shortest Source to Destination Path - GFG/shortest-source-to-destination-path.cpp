//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        A[0][0]=0;
        int dr[]={0,1,0,-1,0};
        while(!q.empty()){
            int st=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x==X && y==Y)return st;
            for(int i=0;i<4;i++){
                int dx=x+dr[i],dy=y+dr[i+1];
                if(dx>=0 && dy>=0 && dx<N && dy<M && A[dx][dy]==1){
                    A[dx][dy]=0;
                    q.push({st+1,{dx,dy}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends