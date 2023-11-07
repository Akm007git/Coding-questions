class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        int ans = INT_MAX;

        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            //if left part sorted
            if(nums[s] <= nums[mid]){
                ans = min(ans,nums[s]); // update the ans
                s = mid+1; // check the right part;
            }
            else // right part is sorted,the mid term will be the lowest one
            {
                ans = min(ans,nums[mid]);
                e = mid-1; // check the left part
            }
                
        }

         return ans;
    }
};