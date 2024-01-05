//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        // foor saving prefixsum with index
        
        int len = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            
            if(sum == 0){// it means , jekahe ache otai maxSubarray
                len = i+1;
            }
            else{
                
                // if already sum ta mapp e pore ache it means
                // means, jotdur porjonto pref sum save ache or porere part tar sum = 0
                // striver logic
                if(mp.find(sum) != mp.end())
                {
                    len = max(len,i-mp[sum]);
                }
                else // if not in map, simply put in map with efx sum
                {
                    mp[sum] = i;
                }
            }
        }
        return len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends