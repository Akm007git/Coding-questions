//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

  long long  isPrime(long long n)
  {
      vector<long long>v(n+1, true);
      long long count =0;
      for(long long i =2;i*i<=n;i++)
      {
          for(int j = i*i; j<=n;j +=i)
          {
              v[j] = false;
          }
      }
      
      for(long long i=2;i*i<=n;i++)
      {
          if(v[i] && i*i <= n)
          {
              count ++;
             // cout<<count<<endl;
          }
      }
      return count;
  }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int >ans;
        for(int i=0;i<q;i++)
        {
            long long count = isPrime(query[i]);
            ans.push_back(count);
            
        }
        return ans;
    
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends