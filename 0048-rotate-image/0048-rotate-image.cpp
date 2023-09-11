class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(); // row size 
	    int m = mat[0].size(); // column size

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(mat[i][j] ,mat[j][i]);
            }
        }

        // step:2 reverse the matrix

        for(int i = 0;i<n;i++)
        {
            int start = 0; // first col index
            int end = m-1; // last col index

            while( start < end)
            {
                swap(mat[i][start], mat[i][end]); // two pointer approach
                start++,end--;
            }
	}
	
    }
};