//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfRowCol(int N, int M, vector<vector<int>> A) {
        // code here
        int  size = min(M,N); // according to question
        for(int i=0;i<size;i++) // traversing outer row wise
        {
            // sum row wise
            int rSum=0,cSum=0;
            for(int r=0;r<N;r++)
            {
                rSum += A[r][i]; // adding row sum
            }
            
            for(int c=0;c<M;c++)
            {
                cSum += A[i][c]; // adding col sum, changing c and as it is left so basically
            }
            
            // check
            if(rSum != cSum)
            {
                return 0;
            }
        }
        return 1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> A[i][j];
        Solution ob;
        cout << ob.sumOfRowCol(N, M, A) << "\n";
    }
}
// } Driver Code Ends