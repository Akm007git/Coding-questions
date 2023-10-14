//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		map<string,int>mp;
		int diff = -1;
		int maxDiff = INT_MAX;
		for(int i=0;i<s.size();i++)
		{
		    mp[s[i]] = i;
		    
		   if(mp.find(word1) != mp.end() && mp.find(word2) != mp.end() )
		   {
		       diff = abs(mp[word1] - mp[word2]);
		       maxDiff =  min(maxDiff,diff);
		   }
		    
		    
		}
		
	
		return maxDiff;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends