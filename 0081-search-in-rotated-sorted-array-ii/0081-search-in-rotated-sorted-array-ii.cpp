class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] == target)
                return 1;

            //Edge case:, if they are equal then skip this part, and update that part one step ahed
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s = s + 1;
                e = e - 1;
                continue;
            }
            // 2 case can be made
            // left part can be sorted
            // if not right obviously sorted, as rotated

            if(nums[s] <= nums[mid]) // means left part sorted
            {
                //check target lied in this range or not
                if(target >= nums[s] && target < nums[mid])
                    e = mid-1; // is in range, then seacrch it
                else
                    s = mid+1; // leave the left part, traverse right
            }
            else // right sorted 
            {
                //check target lied in this range or not
                if(target >nums[mid] && target <= nums[e])
                    s = mid+1;  // is in range, then seacrch it
                else
                    e = mid-1; // leave the right part, not availavle, go to left part
            }

        }
        return 0;
    }
};