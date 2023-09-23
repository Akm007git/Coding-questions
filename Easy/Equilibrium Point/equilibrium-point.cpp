//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int totalsum =0;
        for(int i=0;i<n;i++)
        {
            totalsum += a[i]; // at first  sum all the total
        }
        
        int leftSum =0;
        int rightSum = totalsum;
        
        // for checking the equlibriam index
        for(int i=0;i<n;i++)
        {
            rightSum -= a[i]; // each time reduc the sum and check
            if(leftSum == rightSum)
            {
                return (i+1); // returning index
            }
            else
            {
                leftSum += a[i]; // else add as  lightSum
            }
        }
        return -1;
    }

};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends