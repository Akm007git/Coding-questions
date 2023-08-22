//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
            int totelsum = 0,currsumrow =0,currsumcolumn =0 ;
            int maxsum = INT_MIN;
        
            for(int i=0;i<n;i++){
                currsumrow =0;
                currsumcolumn=0;
                for(int j=0;j<n;j++){
                  currsumrow += matrix[i][j];
                  currsumcolumn += matrix[j][i];
                  totelsum+= matrix[i][j];
                }
                maxsum = max (currsumrow,maxsum);
                maxsum = max (currsumcolumn,maxsum);
        }
        
        return ((n*maxsum)-totelsum);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends