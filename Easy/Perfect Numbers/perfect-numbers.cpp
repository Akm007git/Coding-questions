//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        // edge case
        if(N == 1) 
            return 0;
        
        
        long long  sum = 1;
        long long org = N;
     
        for(int i=2;i<sqrt(N);i++)
        {
            if(N%i == 0)
            {
                sum = sum + i + N/i; 
                // add from front side as well as back side
                // for case 28, when i =2, sum +2 also sum + (28/2)14 = 16
                // when i = 4, sum += 4,7 , then sum = 16+11 = 27, also previously 1 total 28;
            }
        }
        if( sum == org)
        {
            return true;
        }
        else
        {
            return false;
        }
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