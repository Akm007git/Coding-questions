//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        int n = A.size();
        int limit = pow(2,n); // OR I CAN WRITE 1<<N;
        vector<vector<int>>ans;
        
        for(int num = 0;num < limit ;num++)
        {
            vector<int>v;
            
            for(int bit = 0;bit<n;bit++)
            {
                if(num & (1 << bit))
                {
                    v.push_back(A[bit]);
                }
            }
            ans.push_back(v);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends