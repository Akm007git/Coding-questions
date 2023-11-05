class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + ( end-start)/2;

        while( start <= end)
        {
            if(nums[mid] == target )
            {
                return mid;
            }
            
            // two case can be made 
            /*   1. left part can be sorted
            2. right part can be sorted    */

            if( nums[start] <= nums[mid])
            {
                if( target >= nums[start] && target < nums[mid])
                {
                    end = mid-1;
                }
                else
                {
                    start = mid +1;
                }
            }
            else
            {
                if( target <= nums[end] && target > nums[mid])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            mid = start + (end-start)/2;
        }
        return -1;

    }
};