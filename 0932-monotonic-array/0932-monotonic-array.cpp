class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0;
        int dec = 0;
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1])
                inc=1;
            if(nums[i] < nums[i-1])
                dec=1;
        }
        if(inc+dec == 2) // it menas elemnts sufflr lkora ache
        {
            return false;
        }
        else // suffle kora nei
        {
            return true;
        }
    }
};