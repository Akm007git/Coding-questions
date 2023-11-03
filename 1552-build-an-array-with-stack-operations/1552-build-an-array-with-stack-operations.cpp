class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string>ans;
        int i=0; // itteretor of target array
        for(int j=1;j<=n;j++)
        {
            if(i >= target.size()) // IF i EXTEND THE SIZE OF TARGET, THEN BREAK NOT NECESSERY
                break;
            
            if(target[i] == j) // both increase i++,j++
            {
                ans.push_back("Push");
                i++;
            }
            else // if no equal then push----->pop, and only increase j
            {
                ans.push_back("Push");
                ans.push_back("Pop");

            }
        }
        return ans;
    }
};