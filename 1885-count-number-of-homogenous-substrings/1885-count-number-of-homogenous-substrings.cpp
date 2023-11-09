class Solution {
public:
    int countHomogenous(string s) {
        int length = 1;
        int ans = 0;
        int mod = 1e9+7;

        for(int i=1;i<s.size();i++)
        {
            if(s[i] == s[i-1]) // same string
            {
                length += 1;
            }
            else // different string
            {
                length = 1; // set with initial value
            }

            ans = (ans + length) % mod;
        }
        return ans+1;
    }
};