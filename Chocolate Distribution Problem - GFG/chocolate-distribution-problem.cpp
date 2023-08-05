//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    long long ans = INT_MAX;
    int chk =0; // first index of chocolate, lowest cholate given to student
    int stu = m-1; // last index of student and highest chocholate given
    
    
    while(chk < n && stu<n)
    {
        long long minimum = a[stu] - a[chk];
        //each time i have to check in M size student window, first index we gort the lowest chocolate given  and M-1 size is the  highest chocolate given count we can 
        ans = min(ans,minimum);
    chk++,stu++;
    }
    return ans;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends