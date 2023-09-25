class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        char ans ;
        int i=0,j=0;
        while(i<s.size() && j <t.size())
        {
            if(s[i] == t[i])
            {
                i++,j++;
            }
            else
            {
                break;
            }

        }
        return t[j];
        
    }
};