//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        for(auto i :string2)
        {
            int index = string1.find(i);
            if(index != string:: npos) // if charec of string2 avalable in string1
            {
                
                string1.erase(remove(string1.begin(),string1.end(),i),string1.end());
            }
        }
        return string1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends