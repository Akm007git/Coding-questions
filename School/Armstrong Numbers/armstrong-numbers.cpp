//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    
    int findDigit(int n){
        int count = 0;
       
        
        while( n != 0)
        {
            int remd = n%10;
            count++;
            n /= 10;
        }
        return count;
    }
    
        int solve(int n,int count)
        {
            int sum = 0;
            while(n != 0)
            {
                int remd = n%10;
                sum += pow(remd,count);
                n /= 10;
            }
            
            return sum;
        }
  public:
    string armstrongNumber(int n){
        // code here
        int count = findDigit(n);
        //cout<<count<<" ";
        
        int ams = solve(n,count);
        //cout<<ams;
        
         return ams == n ? "Yes" : "No";
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends