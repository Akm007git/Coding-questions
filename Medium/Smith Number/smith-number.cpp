//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int sum_digit(int n)
{
    int sumd = 0;
    while (n > 0)
    {
        int rem = n % 10;
        sumd += rem;
        n = n / 10;
    }
    return sumd;
}
int primeFactors(int n)
{
    int sump = 0;
    while (n % 2 == 0)
    {
        sump += 2;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            sump += sum_digit(i);
            // cout << sump << endl;
            n = n / i;
        }
    }
    if (n > 2)
    {
        sump += sum_digit(n);
    }
    return sump;
}
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }
    return true;
}

    int smithNum(int n) {
        // code here
          int sump = primeFactors(n), sumd = 0;
    if (isPrime(n))
    {
        return 0;
    }
    else
    {
        sumd = sum_digit(n);
    }

    return (sump == sumd);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends