//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
    
    int mini = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(mini > a[i])
        {
            mini = a[i]; // this process i m going to get the minimum value
        }
    }
    
    int secondMin  = INT_MAX;
    
    for(int i = 0;i < n;i++)
    {
        if(secondMin > a[i] && a[i] != mini)
        {
            secondMin= a[i];
        }
    }
    
    
    if(mini && secondMin != INT_MAX)
    {
        return {mini,secondMin};
    }
    else
    {
        return {-1};
    }
}