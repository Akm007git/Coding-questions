//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        map<int,int>mp;
        vector<int>q(K+1,0);
        vector<vector<int>>ans;
        int index;
        
        for(int i=0;i<N;i++)
        {
            mp[arr[i]]++;
            q[K]=arr[i];
            
            for(int j=0;j<=K;j++)
            {
                if(q[j]==arr[i])
                {
                index=j;
                break;
                }
            }

            for(int j=index;j>0;j--)
            {
                if(mp[q[j]]>mp[q[j-1]]) swap(q[j],q[j-1]);
                
                else if(mp[q[j]]==mp[q[j-1]] && q[j]<q[j-1]) swap(q[j],q[j-1]);
                
                else break;
            }
            
            vector<int>temp;
            for(int j=0;j<K && q[j]!=0;j++)
            {
                temp.push_back(q[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends