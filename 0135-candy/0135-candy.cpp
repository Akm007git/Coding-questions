class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n,1),right(n,1);

        // traverse from left and distribute candy
        for(int i=1; i<n;i++){

            // increase onr by one if ratings more

            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }

        }

        // traverse from the right and compare with  neighbour and plus one
        for(int j = n-2; j>=0; j--){
            if(ratings[j] > ratings[j+1])
            {
                right[j] =  right[j+1]+1;
            }
        }

        // summation max of those each array elemnt

        int sum = 0;

        for(int i=0;i<n;i++){
            sum += max(left[i],right[i]);
        }
        return sum;
        
    }
};