class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int s=0;
        int e=n-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i] %2 == 0)
            {
                ans[s] = nums[i];
                s++;
            }
            if(nums[i] %2 != 0 )
            {
                ans[e] = nums[i];
                e--;
            }
        }

        return ans;
        
    }
};