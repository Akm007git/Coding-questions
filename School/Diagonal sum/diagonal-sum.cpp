//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int DiagonalSum(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int leftSum=0,rightSum=0;
        
        for(int i=0;i<n;i++)
        {
            leftSum += matrix[i][i]; // row col same in case of lwft diagonal 0,0  or 1,1  or 2,2
            rightSum += matrix[i][n-i-1]; // this index will be corresponding opposite  cell 0,2 or 1,1 or 2,0
            
        }
        return leftSum+rightSum;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.DiagonalSum(matrix);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends