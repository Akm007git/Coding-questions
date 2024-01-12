//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
    stack<int >s;
    int n = q.size();
    
    //step:1 push upto kth eklement in stack
    for(int i=0; i<k;i++)
    {
        int value = q.front();
        q.pop();
        s.push(value);
    }
    // tstep:2 extract element from stack and push in queue;
    while( !s.empty())
    {
        int num = s.top();
        s.pop();
        q.push(num);
    }
    // step:3 extract the remaining n-k element and push back in the smae queue
    for( int i=0; i<(n-k);i++)  // this could be be while(t--)// when t = n-k;
    {
        int value = q.front();
        q.pop();
        q.push(value);
    }
    return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends