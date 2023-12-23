//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    

  public:
  
    int nthFibonacci(int n){
        // code here
        int mod = 1e9+7;
        int prev1 = 1;
        int prev2 = 0;
        
        for(int i=2;i<=n;i++)
        {
            int current = (prev1%mod + prev2%mod)%mod;
              prev2 = prev1;
              prev1 = current;
            
        }
        
        return prev1;
        
    }
};

/* SPACE OPTIMAIZATION------------------------------------*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends