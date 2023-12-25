//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    int isPerfectNumber(long long N) {
        
        //edge case
          if(N == 1) return 0;
        // code here
        long long  sum  = 1; // we will start sum from sum == 1, as we gonna skip the i = 1, iteration, otherwuaw when we add N/i , it will the number itself
        for(int i=2;i<sqrt(N);i++)
        {
            if(N%i == 0)
            {
                sum += i;
                sum += N/i;
            }
        }
        //cout<<sum<<" "<<endl;
        return sum == N ? 1 : 0;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends