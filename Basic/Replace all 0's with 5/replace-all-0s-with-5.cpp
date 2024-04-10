//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int newnum = 0;
    int sum = 1; // this is thr parameter , ive tonincese each time
    
    while(n != 0)
    {
        int remd = n%10;
        
        if(remd  == 0)
        {
            remd  = 5;
        }
        
        newnum  += remd*sum;
        sum *= 10;
        
        n = n/10;
    }
    return newnum;
}