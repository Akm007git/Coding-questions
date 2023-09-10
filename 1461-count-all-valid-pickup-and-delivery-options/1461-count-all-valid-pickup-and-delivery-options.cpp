class Solution {
public:
    int countOrders(int n) {
         int mod = 1e9+7;

        long answer = 1;
        for(int i=1;i<=n;i++)
        {
            answer = answer*i; // forpickup points permutations;
            answer %=mod;
            answer = answer * (2*i - 1); // for delivery combinations repective to  the pickup  points
            answer %= mod;
        }
        return answer;
        
    }
};

