//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

// cocept of sieve of eratosthenis


  long long  isPrime(long long n)
  {
      vector<long long>v(n+1, true); // initilize all elemnt as true
      long long count =0;
      for(long long i =2;i*i<=n;i++) // limit squart of n
      {
          for(int j = i*i; j<=n;j +=i)
          {
              v[j] = false; // marking false the divisable of 2, 3 , if get
          }
      }
      
      for(long long i=2;i*i<=n;i++) 
      {
          if(v[i] && i*i <= n) // checking if the elemnt true or not and if true, its square in the range or not 
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
            long long count = isPrime(query[i]); // each time passing single query
            ans.push_back(count); // store in vector
            
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