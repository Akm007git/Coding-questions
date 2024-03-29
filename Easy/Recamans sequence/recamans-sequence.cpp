//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> v;
        map<int,int> m;
        m[0]++;
        v.push_back(0);
        for(int i = 1; i<n; i++)
        {
            if(((v[i-1] - i) < 0) || m.find(v[i-1]-i) != m.end())
            {
                m[v[i-1]+i]++;
                v.push_back(v[i-1]+i);
            }
            else 
            {
                v.push_back(v[i-1]-i);
                m[v[i-1]-i]++;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends