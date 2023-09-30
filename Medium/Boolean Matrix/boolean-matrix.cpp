//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int row = matrix.size();
        int col = matrix[0].size();
        
        // taking two separe arr
        int arr_row[row] = {0};
        int arr_col[col] = {0};
        
        // taking the row and col from the matrix array
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == 1)
                {
                    arr_row[i] = 1;
                    arr_col[j] = 1;
                }
            }
        }
        
        // modify the array fill with 1 row wise
        // here row fixed and traverse col wise
        for(int i=0;i<row;i++)
        {
            if(arr_row[i] == 1) // ith row
            {
                for(int j=0;j<col;j++)
                {
                    matrix[i][j] = 1; // mark 1 all the row using the column
                }
            }
        }
        
        // modify the array fill with 1 colm wise
        
        // here col fixed traverse with row wise
        
        for(int j=0;j<col;j++)
        {
            if(arr_col[j] == 1)
            {
                for(int i=0;i<row;i++)
                {
                    matrix[i][j] = 1;  // mark 1 all the col  using the row
                }
            }
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends