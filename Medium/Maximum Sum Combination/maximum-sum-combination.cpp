//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public: 
  
  bool static comp(int a, int b){
        return a>b;
    }
  
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end(), comp);
        sort(B.begin(), B.end(), comp);
        priority_queue< int, vector<int>, greater<int> >pq;
        
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                int sum=A[i]+B[j];
                if(pq.size()<K) pq.push(sum);
                else if(pq.size()==K && sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }else if(pq.size()==K && sum<=pq.top()) break;
            }
        }
        vector<int>ans(K);
        for(int i=K-1; i>=0; i--){
            ans[i]=pq.top();
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends