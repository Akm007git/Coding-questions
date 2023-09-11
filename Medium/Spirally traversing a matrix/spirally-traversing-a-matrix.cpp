//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        // int rowSize = matrix.size();
        // int colSize = matrix[0].size();
        
        int totalSize = r * c;
        
        int rowStart = 0, rowEnd = r-1;
        int colStart = 0,colEnd = c-1;
        
        vector<int>ans;
        int count = 0 ;
        
        while( count < totalSize)
        {
            // print left - right rowWise // UPPER ROW
            
            for(int  i = colStart ; i<=colEnd && count < totalSize ;i++)
            {
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;
            
            //  print right colm // up to down
            
            for(int i = rowStart ; i<=rowEnd && count < totalSize;i++ )
            {
                ans.push_back(matrix[i][colEnd]); //..
                count++;
            }
            colEnd--;
            
            // print down row right to left
            
            for(int i= colEnd;i>=colStart && count < totalSize;i--)
            {
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;
            
            // left colm print down to up
            
            for(int i = rowEnd;i>=rowStart && count < totalSize;i--)
            {
                ans.push_back(matrix[i][colStart]); //..
                count++;
            }
            colStart++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends