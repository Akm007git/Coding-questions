//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void Multiply(vector<vector<int> >& A, vector<vector<int>>&B) {
        // Code here
        int N = A.size();
        vector<vector<int>>ans(N,vector<int>(N,0));
        for(int i=0;i<N;i++) // row wise
        {
          for(int j=0;j<N;j++) // col wise
          {
              int sum = 0;
              for(int k=0;k<N;k++) // for store sum
              {
                  sum += A[i][k]*B[k][j]; // [row][col] * [col][row] // main logic
                  ans[i][j] = sum; // after each box added , j will update and agin k = 0---->N
              }
           }
       }
      
         for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                A[i][j]=ans[i][j];
            }
         }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrixA(n, vector<int>(n,0));
		vector<vector<int>> matrixB(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixA[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixB[i][j];
			}
		}
		Solution ob;
		ob.Multiply(matrixA, matrixB);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrixA[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends