//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    
    bool isSorted(vector<int>&v)
    {
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i] >= v[i+1])
            {
                return 0;
            }
        }
        return 1;
    }
    
    private:
    
    bool iSreverseSorted(vector<int>&v)
    {
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i] <= v[i+1])
            {
                return 0;
            }
        }
        return 1;
    }
    
  public:
    int sortedCount(int N, int M, vector<vector<int>> Mat) {
        // code here
        int count = 0;
        for(auto it:Mat)
        {
           if(isSorted(it) || iSreverseSorted(it))
           {
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.sortedCount(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends