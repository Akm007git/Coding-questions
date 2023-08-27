class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>pq;

        set<int>dist;
        // inserting all elemnt from arr to set
        for( auto i: nums)
        {
            dist.insert(i);
        }

    //inserting distinct veelement from setvto priority queue 
        for(auto i:dist)
        {
            pq.push(i);
        }
        //condition for edge case
        if(pq.size() < 3)
        {
            return pq.top();
        }
        
        // main logic

        int count =0;
        while( count != 2 && !pq.empty())
        {
            pq.pop();
            count++;
            
        }
        return pq.top();

        



       
    }
};