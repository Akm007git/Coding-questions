//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here
        int n = str.size();
        int number =0;
       int  power =0;
        for(int i=n-1;i>=0;i--)
        {
            
            if(str[i] == '1')
            {
                number +=  (str[i]-'0') * pow(2,power); // i can use 1 rather than  str[i]-'0'
            }
            power++;
            
        }
        return number;
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends