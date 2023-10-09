class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first = -1;
        int last = -1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                // only for first time , we abale to get the first index
                if(first == -1)
                {
                    first = i;
                    
                }
                // for the last index
                    last = i;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};