//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    int findCount(int n)
    {
        int count  = 0;
        while(n)
        {
            int remd = n%10;
            count++;
            n = n/10;
        }
        
        return count;
    }
    
    bool isAmstrong(int n, int count)
    {
        int org = n;
        int sum  = 0;
        while(n)
        {
            int remd  = n%10;
            sum  += pow(remd,count);  //1^3 + 5^3 + 3^3;
            
            n = n/10;
            
        }
        
        if(sum == org) return true;
        else return false;
    }
  public:
    string armstrongNumber(int n){
        // code here
        int count  = findCount(n);
        bool ans  = isAmstrong(n,count);
        
        if(ans) return "Yes";
        else return "No";
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