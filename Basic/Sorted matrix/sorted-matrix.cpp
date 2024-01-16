//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int n = Mat.size(); // row size
        int m = Mat[0].size(); // col size
        
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v.push_back(Mat[i][j]);
            }
        }
        
        // printed all the elemnt lineartly
        sort(v.begin(),v.end()); // sorted done
        
        vector<vector<int> >ans(n,vector<int>(m,0));
        
        // for(auto it:v)
        // {
        //     cout<<it<<" ";
        // }
        
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j] = v[k++];
            }
        }
        
        return ans;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends