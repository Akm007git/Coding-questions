//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<pair<int,int>> pa;
        for(int i=0; i<n; i++){
            pa.push_back({a[i],i});
        }
        sort(pa.begin(),pa.end());
        vector<int> suf(n,pa[n-1].second);
        int maxi=0;
        for(int i=n-2; i>=0; i--){
            int r=pa[i].second;
            suf[i]=max(suf[i+1],r);
            maxi=max(maxi,suf[i]-r);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends