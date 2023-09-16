//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        long a =1;long sum=0;
        long b=2;
        long c =4;
        if(n==1)return a;
        else if(n==2)return b;
        else if(n==3)return c;
        
        else if(n>3){
            while(n-3>0){
                sum = (a+b+c)%1000000007;
                a =b;
                b=c;
                c=sum;
                n--;
            }
        }
        return sum%1000000007; 
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends