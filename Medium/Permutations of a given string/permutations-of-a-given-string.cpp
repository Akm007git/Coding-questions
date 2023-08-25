//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void solve(string s, vector<string>&v,int index)
	{
	    // base  case
	    if(index >= s.size())
	    {
	        v.push_back(s);
	        return;
	    }
	    
	    
	    for(int j=index;j<s.size();j++ )
	    {
	        swap(s[index],s[j]);
	        
	        // recusrsive call
	        solve(s,v,index+1);
	        
	        // backtracking
	        swap(s[index],s[j]);
	    }
	}
	
	

		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    int index = 0;
		    solve(S,ans,index);
		    sort(ans.begin(),ans.end());
		    set<string>st;
		    for(auto it :ans)
		    {
		        st.insert(it);
		    }
		    
		    vector<string>vv;
		    for(auto it:st)
		    {
		        vv.push_back(it);
		    }
		    return vv;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends