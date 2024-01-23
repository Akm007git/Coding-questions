//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>v;
        
        int i = 0;
        while(i < n) // row wise iteration
        {
            // left to write when row even position
           if(i%2 == 0)
           {
                for(int j=0;j<m;j++)
                {
                    v.push_back(matrix[i][j]);
                }
           }
        else  // whrn row odd position
        {
            for(int j = m-1;j>=0;j--)
            {
                v.push_back(matrix[i][j]);
            }
        }
              i++;
        }
           return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends