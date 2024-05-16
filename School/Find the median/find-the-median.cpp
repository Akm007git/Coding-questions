//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		   int n  = v.size();
		   
		   sort(v.begin(),v.end()); // sorting the array
		   int ans = 0;
		   if(n%2 == 0) // if even
		   {
		       int index = v[((n/2)-1)] + v[(n/2)];
		       ans = index/2;
		       return ans;
		   }
		   else
		   {
		       return v[n/2];
		   }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends