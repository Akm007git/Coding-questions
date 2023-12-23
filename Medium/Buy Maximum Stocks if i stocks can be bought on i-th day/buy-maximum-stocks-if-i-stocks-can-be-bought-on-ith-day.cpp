//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
         vector<pair<int,int>>v;
        int ans=0;
        //make pair
        for(int i=0;i<n;++i)
        {
            v.push_back({price[i],i+1});
        }
        // got the idea of sorting from time complexity
        sort(v.begin(),v.end());
        for(int i=0;i<n;++i)
        {
            int stocks=k/v[i].first;
            int temp=min(stocks,v[i].second); // we require this because if stocks count comes greater than available quantity
            k=k-temp*v[i].first;
            ans+=temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends