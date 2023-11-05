class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int count =0;
        int winner = arr[0];

        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] > winner) //each time when we got new winner
            {
                winner = arr[i]; // update the winner
                count=1; // also set the count count of that winner
            }
            else
            {
                count++; // whenever no new winner , it means consecutive winner available;
            }

            if(count == k){
                return winner;
            }
            
        }
        return winner;
    }
};