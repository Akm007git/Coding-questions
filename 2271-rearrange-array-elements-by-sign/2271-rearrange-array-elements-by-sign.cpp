class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int>ans;
        queue<int>pos;
        queue<int>neg;

    for(int i=0;i<a.size();i++)
    {
        if(a[i] > 0)
            pos.push(a[i]);
        else
            neg.push(a[i]);
        
    }

    while(!pos.empty() && !neg.empty())
    {
        int f = pos.front();
        pos.pop();
        ans.push_back(f);
        int n = neg.front();
        neg.pop();
        ans.push_back(n);
    }
    return ans;
    
    }
};