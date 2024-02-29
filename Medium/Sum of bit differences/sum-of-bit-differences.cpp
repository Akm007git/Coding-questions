//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	      long ans=0;
        for(int j=0;j<32;j++){
            int one=0;
            int zero=0;
            for(int i=0;i<n;i++){
                if(arr[i]%2==0) zero++;
                else one++;
                arr[i]=arr[i]/2;
            }
            ans+=(long)one*zero;
        }
        return (long)ans*2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends