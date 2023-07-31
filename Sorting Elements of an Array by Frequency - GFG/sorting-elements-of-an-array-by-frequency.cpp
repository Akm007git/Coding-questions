#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 bool comp(pair<int,int>a , pair<int,int>b)
{
        if(a.second ==  b.second)
        {
           return  a.first < b.first;
        }
        else
        {
            return a.second > b.second;
        }
        
        
}





int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    
	    // mapping with count
	    unordered_map<int,int>mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[v[i]]++;
	    }
	    
	    vector<pair<int,int> >freq(mp.begin(),mp.end());
	    
	    sort(freq.begin(),freq.end() ,comp);
	    
	    vector<int>ans;
	    
	    for(auto it : freq)
	    {
	        while(it.second != 0)
	        {
	            ans.push_back(it.first);
	            it.second--;
	        }
	    }
	    
	    for(int i=0;i<ans.size();i++)
	    {
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}