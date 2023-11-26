//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        int org = N;
        vector<int>v;
        
        while(N > 0)
        {
            v.push_back(N);
            N -= 5;
        }
        
        // now n is reduced, but value is already store  in org
        
        while( N <= org)
        {
            v.push_back(N);
            N += 5;
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends