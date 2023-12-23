//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        int count =0; // fot storing how much element's count>num
        int num =n/k;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[ arr[i]] += 1; // marking all digit 1;
            
            if(mp[arr[i]]>num)
            {
                count++; // kono digit store howar por or count k extremly negetive kortehobe jate next time abar na count hoi
             mp[arr[i]] = INT_MIN;
            }
        }
        return count;
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

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends