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
    int sum = 1;
    int newNum = 0;
    
    while(n != 0)
    {
        int remd = n%10;
        if(remd == 0)
        {
            remd = 5;
        }
        
        newNum += remd*sum; // again re constructing the number
        sum = sum*10; //  update the sum each time  *10
        
        // update the provided number
        n /= 10;
    }
    return newNum;
}